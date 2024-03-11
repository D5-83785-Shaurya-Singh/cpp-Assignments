#include <iostream>
using namespace std;

class Student
{
    string name;
    char gender;
    int roll_no;
    double physics;
    double chemistry;
    double mathematics;

    public: 
        Student()
        {
            this->name = "default";
            this->gender = 'f';
            this->roll_no = 1;
            this->physics = 100;
            this->chemistry = 100;
            this->mathematics = 100;
        }

        Student(string name, char gender, int roll_no, int physics, int chemistry, int mathematics)
        {
            this->name = name;
            this->gender = gender;
            this->roll_no = roll_no;
            this->physics = physics;
            this->chemistry = chemistry;
            this->mathematics = mathematics;
        }

        int getRollno()
        {
            return this->roll_no;
        }

        void acceptStudentDetails()
        {
            cout << "Enter Student name: " << endl;
            cin >> this->name;
            cout << "Enter gender: " << endl;
            cin >> this->gender;
            cout << "Enter roll number: " << endl;
            cin >> this->roll_no;
            cout << "Marks in Physics: " << endl;
            cin >> this->physics;
            cout << "Marks in Chemistry: " << endl;
            cin >> this->chemistry;
            cout << "Marks in Mathematics: " << endl;
            cin >> this->mathematics;
        }

        void displayStudentDetails()
        {
            cout << "Roll number: " << this->roll_no;
            cout << "Name: " << this->name << endl;
            cout << "Gender: " << this->gender << endl;
            cout << "Percentage: " << ((this->physics + this->chemistry + this->mathematics)/3) << endl;
        }
};

void sortStudents(Student arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        Student key = arr[i];
        int j = i-1;

        while (j >=0 && arr[j].getRollno() > key.getRollno())
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int searchRecords(Student arr, int size)
{
    int ch;
    cout << "Enter roll number to fetch student details: " << endl;
    cin >> ch;
    for(int i = 0; i < size; i++)
    {
        if(ch == arr.getRollno())
        {
            arr.displayStudentDetails();
            return 1;
        }

        cout << "Student does not exist!!" << endl;
        return -1;
        
    }
}


//Student *arr[3];
int main(void)
{
    int size;
    cout << "Enter size of array of objects: " << endl;
    cin >> size;

    Student arr[size];
    // for(int i = 0; i < size; i++)
    // {
    //     arr[i] = new Student();
    // }


    int choice;
    do
    {
        cout << "Please enter choice: " << endl;
        cout <<"0. Exit\n" << "1. Enter Student details\n" << "2. Display Student details\n" << "3. Sort and print\n" << "4. Fetch Student details\n"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Exiting the program!!" << endl;
            break;

        case 1:
            for(int i = 0; i < size; i++)
            {
                arr[i].acceptStudentDetails();
            }
            break;
        case 2:
            for(int i = 0; i < size; i++)
            {
                arr[i].displayStudentDetails();
            }
            break;

        case 3:
            sortStudents(arr, size);
            
            for(int i = 0; i < size; i++)
            {
                arr[i].displayStudentDetails();
            }
            break;


        case 4:
            for(int i = 0; i < size; i++)
            {
                int y = searchRecords(arr[i], size);
                if(y == -1)
                {
                    cout << "No student found with  the given roll number!!" << endl;
                }
            }

            break;

        default:
            cout << "Invalid choice!!" << endl;
            break;
        }
    } while (choice != 0);
    
}