#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public:
        Date()
        {
            this->day = 1;
            this->month = 1;
            this->year = 1;
        }

        Date(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        int getDay()
        {
            return this->day;
        }

        void setDay(int day)
        {
            this->day = day;
        }

         int getMonth()
        {
            return this->month;
        }

        void setMonth(int month)
        {
            this->month = month;
        }

         int getYear()
        {
            return this->year;
        }

        void setYear(int year)
        {
            this->year = year;
        }

        void acceptDate()
        {
            cout << "Enter date: "<< endl;
            cin >> this->day;
            cout << "Enter month: "<< endl;
            cin >> this->month;
            cout << "Enter year: "<< endl;
            cin >> this->year;
        }

        void displayDate()
        {
            cout << this->day << ":" << this->month << ":" << this->year << endl;
        }
};

class Person
{
    string name;
    string address;
    Date dob;  //Association //Composition //Tight coupling

    public:
        Person()
        {
            this->name = name;
            this->address = name;
        }

        Person(string name, string address, int day, int  month, int year) : dob(day, month, year)
        {
            this->name = name;
            this->address = address;
        }

        string getName()
        {
            return this->name;
        }

        void setName(string name)
        {
            this->name = name;
        }

        string getAddress()
        {
            return this->address;
        }

        void setAddress(string address)
        {
            this->address = address;
        }

        void acceptPerson()
        {
            cout << "Enter name of person: " << endl;
            cin >> this->name;
            cout << "Enter address: " << endl;
            cin >> this->address;
            cout << "Enter Date of birth: " << endl;
            dob.acceptDate();
        }

        void displayPerson()
        {
            cout << "Name of person is " << this->name << endl;
      
            cout << "Address of person is " << this->address << endl;
  
            cout << "Date of birth: " << endl;
            dob.displayDate();
        }

};

class Employee : public Person
{
    int empid;
    float salary;
    string dept;
    Date doj;  //Association //Composition //Tight coupling

    public:
        Employee()
        {
            this->empid = 1;
            this->salary = 10000;
            this->dept = "default";
        }

        Employee(int empid, float salary, string dept, int day, int month, int year) : doj(day, month, year)
        {
            this->empid = empid;
            this->salary = salary;
            this->dept = dept; 
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

        string getDept()
        {
            return this->dept;
        }

        void setDept(string dept)
        {
            this->dept = dept;
        }

        void acceptEmployee()
        {
            cout << "Enter details of person: " << endl;
            this->acceptPerson();
            cout << "Please enter Employee id: " << endl;
            cin >> this->empid;
            cout << "Please enter Employee salary: " << endl;
            cin >> this->salary;
            cout << "Please enter Employee department: " << endl;
            cin >> this->dept;
            cout << "Enter employee joining date: " << endl;
            doj.acceptDate();
        }

        void displayEmployee()
        {
            cout << "Person details: "; 
            this->displayPerson();
            cout << "Employee id: " << this->empid << endl;
            cout << "Employee salary: " << this->salary << endl;
            cout << "Employee department: " << this->dept << endl; 
            cout << "Date of joining: ";
            doj.displayDate();
        }
};

int main(void)
{
    int size;
    cout << "Enter number of employees: " << endl;
    cin >> size;

    Employee arr[size];
    for(int i = 0; i < size; i++)
    {
        arr[i];
    }

    cout << "Enter Employee details: " << endl;
    for(int i = 0; i < size; i++)
    {
        arr[i].acceptEmployee();
    }

    cout << "Displaying all the employee details: " << endl;
    for(int i = 0; i < size; i++)
    {
        arr[i].displayEmployee();
    }

}

