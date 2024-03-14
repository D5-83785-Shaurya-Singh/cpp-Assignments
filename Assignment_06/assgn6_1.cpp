#include <iostream>
using namespace std;

class Employee
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

        virtual void accept()
        {
            
            cout << "Please enter Employee id: " << endl;
            cin >> this->empid;
            cout << "Employee salary is " << endl;
            cin >> this->salary;
        
        }

        virtual void display()
        {
            cout << "Employee ID is " << this->empid << endl;
            cout << "Employee salary is " << this->salary << endl;
        }
};

class Manager : virtual public Employee
{
    float bonus;

    protected:
        void acceptManager()
        {
            cout << "Please enter manager bonus: " << endl;
            cin >> this->bonus; 
        }

        void displayManager()
        {
            cout << "Manager bonus is " << this->bonus << endl;
        }

    public: 
        Manager()
        {
            cout << "Inside parameterless constructor of Manager class" << endl;
            bonus = 1000;
        }

        Manager(int empid, float salary, float bonus) : Employee(empid, salary)
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

        void accept()
        {
            Employee::accept();
            this->acceptManager();
            
        }

        void display()
        {
            Employee::display();
            this->displayManager();
            
        }
};

class Salesman : virtual public Employee
{
    float comm;

    protected:
        void acceptSalesman()
        {
            cout << "Please enter commission " << endl;
            cin >> this->comm;
        }

        void displaySalesman()
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

        void accept()
        {
            Employee::accept();
            this->acceptSalesman();
        }

        void display()
        {
            Employee::display();
            this->displaySalesman();
        }
};

class SalesManager : public Manager, public Salesman
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

    void accept()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};





int main(void) 
{
    //testing the above classes by making objects and calling overridden functions

    Employee e1;  //creating object ogf class Employee
    e1.accept();
    e1.display();

    Manager m1; //creating object of class Manager
    m1.accept();
    m1.display();

    Salesman s1; //creating object of class Salesman
    s1.accept();
    s1.display();

    SalesManager sm1; //creating object of class SalesManager
    sm1.accept();
    sm1.display();

    return 0;

}