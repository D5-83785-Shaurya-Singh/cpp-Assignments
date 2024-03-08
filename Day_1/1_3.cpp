#include <iostream>
using namespace std;

class Student
{
    int roll_no;
    string name;
    int marks;

    public:

        void initStudent()
        {
            this->roll_no = 123;
            this->name = "default";
            this->marks = 100;
        }

        void printStudentOnConsole()
        {
            cout << "Roll number: " << this->roll_no << endl;
            cout << "Name of student: "<< this->name << endl;
            cout << "Marks of student: "<< this->marks << endl;
        }

        void acceptStudentFromConsole()
        {
            cout << "Please enter roll number of student: "<<endl;
            cin >> this->roll_no;
            cout << "Please enter name of student: "<<endl;
            cin >> this->name;
            cout << "Please enter marks of student: "<<endl;
            cin >> this->marks;

        }

};

int main(void)
{
    struct Student s1;
    int choice;

   do
   {
     cout << "0. Exit\n" <<"1. To initialize Student\n"<<"2. Print Student details:\n" << "3. Enter new Student details:"<<endl;
     cin >> choice;
     switch(choice)
     {
        case 0:
            cout << "Exiting program"<< endl;
            break;

        case 1:
            s1.initStudent();
            break;
        case 2:
           s1.printStudentOnConsole();
           break;

        case 3:
            s1.acceptStudentFromConsole();
            break;
     }
   } while (choice != 0);

   return 0;
   
}