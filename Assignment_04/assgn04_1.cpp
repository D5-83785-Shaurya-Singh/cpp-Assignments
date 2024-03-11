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
            this->year = 2024;
        }

        Date(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        int getDay() const
        {
            return this->day;
        }

        void setDay(int day)
        {
            this->day = day;
        }

        int getMonth() const
        {
            return this->month;
        }

        void setMonth(int month)
        {
            this->month = month;
        }

        int getYear() const
        {
            return this->year;
        }

        void setYear(int year)
        {
            this->year = year;
        }

        void acceptDate()
        {
            cout << "Enter day: " << endl;
            cin >> this->day;
            cout << "Enter month: " << endl;
            cin >> this->month;
            cout << "Enter year: " << endl;
            cin >> this->year;
        }

        void displayDate()
        {
            cout << "Day: " << this->day << ":" << "Month: " << this->month << "Year: " << this->year << endl;
        }
};

class Person 
{
    string name;
    string address;
    Date birth_date; //Association  //tight coupling //Composition

    public:
        Person()
        {
            this->name = "abc";
            this->address = "xyz";
        }

        Person(string name, string address, int day, int month, int year) : birth_date(day, month, year)
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

        Date getBirthDate()
        {
            return this->birth_date;
        }

        void setBirthDate(Date birth_date)
        {
            this->birth_date = birth_date;
        }

        void acceptPerson()
        {
            cout << "Enter name of person: " << endl;
            cin >> this->name;
            cout << "Enter address: " << endl;
            cin >> this->address;
            cout << "Enter Date of birth: " << endl;
            birth_date.acceptDate();
        }

        void displayPerson()
        {
            cout << "Name: " << this->name << ":" << "Address: " << this->address << endl;
            cout << "Date of Birth: ";
            birth_date.displayDate();
        }


};

class Employee : Person
{
    private:
        int id;
        float salary;
        string dept;
        Date joining;//Association //tight coupling //Composition

    public:

        Employee()
        {
            this->id = 123;
            this->salary = 50000.00;
            this->dept = "default";
        }

        Employee(int id, float salary, string dept, int day, int month, int year) : joining(day, month, year)
        {
            this->id = id;
            this->salary = salary;
            this->dept = dept;
        }

        int getId()
        {
            return this->id;
        }

        void setId(int id)
        {
            this->id = id;
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

        void setdept(string dept)
        {
            this->dept = dept;
        }

        void acceptEmployee()
        {
            cout << "Enter employee id: " << endl;
            cin >> this->id;
            cout << "Enter employee salary: " << endl;
            cin >> this->salary;
            cout << "Enter department of employee: " << endl;
            cin >> this->dept;
            cout << "Employee details: ";
            this->acceptPerson();
            cout << "Enter date of joining: ";
            joining.acceptDate();
        }

        void displayEmployee()
        {
            cout << "Employee id: " << this->id << endl;
            cout << "Employee salary: " << this->salary << endl;
            cout << "Employee department: " << this->dept << endl;
            cout << "Employee's details: "; 
            this->displayPerson();
            cout << "Date of joining: ";
            joining.displayDate();
        }

};

int main(void)
{

    Employee e1;
    e1.acceptEmployee();
    e1.displayEmployee();
    int id;
    cout << "Enter different employee id: " << endl;
    cin >> id;
    e1.setId(id);

    e1.displayEmployee();
}