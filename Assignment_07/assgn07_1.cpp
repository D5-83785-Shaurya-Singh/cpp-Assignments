#include <iostream>
using namespace std;

class Employee  //Parent class
{
    int empid;
    float salary;

    public:

        Employee()
        {
            cout << "Inside parameterless constructor of Employee class " << endl;
            empid = 1;
            salary = 1000;
        }

        Employee(int empid, float salary)
        {
            cout << "Inside parameterized constructor of Employee class " << endl;
            this->empid = empid;
            this->salary = salary;
        }
        
        int getEmpid()
        {
            return this->empid;
        }

        void setEmpid(int empid)
        {
            this->empid = empid;
        }

        float getSalary()
        {
            return this->salary;
        }

        void setSalary(float salary)
        {
            this->salary = salary;
        }

        virtual void accept() //will be overridden
        {
            
            cout << "Please enter Employee id: " << endl;
            cin >> this->empid;
            cout << "Employee salary is " << endl;
            cin >> this->salary;
        
        }

        virtual void display()  //will be overridden
        {
            cout << "Employee ID is " << this->empid << endl;
            cout << "Employee salary is " << this->salary << endl;
        }
};

class Manager : virtual public Employee  //derived class //heirarchical inheritance
{
    float bonus;

    protected:
        void acceptManager()  //implementing this function seperately to avoid diamond problem
        {
            cout << "Please enter manager bonus: " << endl;
            cin >> this->bonus; 
        }

        void displayManager() //implementing this function seperately to avoid diamond problem
        {
            cout << "Manager bonus is " << this->bonus << endl;
        }

    public: 
        Manager()
        {
            cout << "Inside parameterless constructor of Manager class" << endl;
            bonus = 1000;
        }

        Manager(int empid, float salary, float bonus) : Employee(empid, salary) //constructor delegation
        {
            cout << "Inside manager parametrized constructor " << endl;
            this->setEmpid(empid);
            this->setSalary(salary);
            this->bonus = bonus;
        }

        float getBonus()
        {
            return this->bonus;
        }

        void setBonus(float bonus)
        {
            this->bonus = bonus;
        }

        void accept()  //overridden function
        {
            Employee::accept();
            this->acceptManager();
            
        }

        void display() //overridden function
        {
            Employee::display();
            this->displayManager();
            
        }
};

class Salesman : virtual public Employee  //derived class //heirarchical inheritance
{
    float comm;

    protected:
        void acceptSalesman()  //implementing this function seperately to avoid diamond problem
        {
            cout << "Please enter commission " << endl;
            cin >> this->comm;
        }

        void displaySalesman() //implementing this function seperately to avoid diamond problem
        {
            cout << "Salesman commission is " << this->comm << endl;
        }

    public: 
        Salesman()
        {
            cout << "Inside parameterless construcutor of Salesman class " << endl;
            comm = 100;
        }

        Salesman(int empid, float salary, float comm) : Employee(empid, salary)
        {
            cout << "Inside parameterized construcutor of Salesman class " << endl;
            this->setEmpid(empid);
            this->setSalary(salary);
            this->comm = comm;
        }

        float getComm()
        {
            return this->comm;
        }

        void setComm(float comm)
        {
            this->comm = comm;
        }

        void accept()  //overridden function
        {
            Employee::accept();
            this->acceptSalesman();
        }

        void display()   //overridden function
        {
            Employee::display();
            this->displaySalesman();
        }
};

class SalesManager : public Manager, public Salesman  //child class // multiple inheritance
{
    public:
    SalesManager()
    {
        cout << "Inside parameterless constructor of SalesManager class " << endl;
    }

    SalesManager(int empid, float salary, float bonus, float comm) 
    {
        cout << "Inside parameterized constructor of SalesManager class " << endl;
        this->setEmpid(empid);
        this->setSalary(salary);
        this->setBonus(bonus);
        this->setComm(comm);
    }

    void accept()    //overridden function
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display()   //overridden function
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};



int main(void)
{
    Employee *arr[10];
    int choice, count = 0, emp = 0, man = 0, sales = 0, sm = 0;
    
    do
    {
        cout << "Please enter choice: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Create new employee " << endl;
        cout << "2. Create new Manager " << endl;
        cout << "3.Create new Salesman " << endl;
        cout << "4.Create new SalesManager " << endl;
        cout << "5. Display employees with respect to designation" << endl;
        cout << "6. Display all managers" << endl;
        cout << "7. Display all salesman" << endl;
        cout << "8. Display all Salesmanagers" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting program!!" << endl;
            break;

        case 1:
            {
                if(count < 10)
                { 
                            arr[count] = new Employee();
                            arr[count]->accept();
                            cout << "====New Employee is created====" << endl;
                            emp++;
                            count++;
            
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                    
                
            }
            break;

        case 2:
            {
                if(count < 10)
                { 
                            arr[count] = new Manager();
                            arr[count]->accept();
                            cout << "====New Manager is created====" << endl;
                            man++;
                            count++;
                  
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                
            }
            break;

        case 3:
            {
                if(count < 10)
                { 
                            arr[count] = new Salesman();
                            arr[count]->accept();
                            cout << "====New Salesman is created====" << endl;
                            sales++;
                            count++;
            
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                
            }
            break;

        case 4:
            {
                if(count < 10)
                { 
                            arr[count] = new SalesManager();
                            arr[count]->accept();
                            cout << "====New SalesManager is created====" << endl;
                            sm++;
                            count++;
            
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                
            }
            break;
        case 5:

            {
                for(int i = 0; i < count; i++)
                {
                    if(typeid(Employee) == typeid(*arr[i]))
                    {
                        cout << "Details of Employee: " << endl;
                        arr[i]->display();
                    }

                    else if (typeid(Manager) == typeid(*arr[i]))
                    {
                        cout << "Details of Manager: " << endl;
                        arr[i]->display();
                       // man++;
                    }

                    else if (typeid(Salesman) == typeid(*arr[i]))
                    {
                        cout << "Details of Salesman: " << endl;
                        arr[i]->display();
                        //sales++;
                    }

                    else if (typeid(SalesManager) == typeid(*arr[i]))
                    {
                        cout << "Details of SalesManager: " << endl;
                        arr[i]->display();
                        //sm++;
                    }
                }
                cout << "Number of employees are " << emp << endl;
                cout << "Number of managers are " << man << endl;
                cout << "Number of salesman are " << sales << endl;
                cout << "Number of sales managers are " << sm << endl;
                
            }
            break;

        case 6:
            for(int i = 0; i < count; i++)
                {
                    if(typeid(Manager) == typeid(*arr[i]))
                    {
                        cout << "Details of Manager: " << endl;
                        arr[i]->display();
                    }
                }
                break;

        case 7:
             for(int i = 0; i < count; i++)
                {
                    if(typeid(Salesman) == typeid(*arr[i]))
                    {
                        cout << "Details of Salesman: " << endl;
                        arr[i]->display();
                    }
                }
                break;

        case 8:
             for(int i = 0; i < count; i++)
                {
                    if(typeid(SalesManager) == typeid(*arr[i]))
                    {
                        cout << "Details of SalesManager: " << endl;
                        arr[i]->display();
                    }
                }
                break;
        default:
            cout << "Invalid choice!!" << endl;
            break;
        }
        
        
    } while (choice != 0);

    return 0;
    
}