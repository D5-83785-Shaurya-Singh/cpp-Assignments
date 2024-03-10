#include <iostream>
using namespace std;

class Time
{
    int hr;
    int min;
    int sec;

    public:

        Time()
        {
            this->hr = 10;
            this->min = 10;
            this->sec = 10;
        }

        Time(int hr, int min, int sec)
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }

        int getHour() const
        {
            return this->hr;
        }

        void setHour(int hr)
        {
            this->hr = hr;
        }

        int getMinute() const
        {
            return this->min;
        }

        void setMinute(int min) 
        {
            this->min = min;
        }

        int getSeconds() const
        {
            return this->sec;
        }

        void setSeconds(int sec)
        {
            this->sec = sec;
        }

        void acceptTime()
        {
            cout << "Enter hours: ";
            cin >> this->hr;
            cout << "Enter minutes: ";
            cin >> this->min;
            cout << "Enter seconds: ";
            cin >> this->sec;

        }

        void displayTime()
        {
            cout << "Time is: "<< this->hr<<":"<< this->min<< ":"<<this->sec<< "\n";
            
        }
};

/*enum FUN
{
    EXIT, ACCEPT, DISPLAY
};*/

int main(void)
{
    Time arr1[5] = {Time(1,2,3), Time(2,3,4), Time(3,4,5), Time(4,5,6), Time(5,6,7)};//created on stack

    Time *arr2[3];//array of pointers of type Time
    arr2[0] = new Time[1]{Time(2,4,6)};//used new keyword thus created on heap dynamically
    arr2[1] = new Time[1]{Time(4,6,8)};
    arr2[2] = new Time[1]{Time(6,8,10)};

    for(int i = 0; i < 3; i++)
    {
        arr2[i]->displayTime();//calling displayTime function on dynamically created objects of Time class
    }

    //Time *arr3[2] = new Time[2]{Time(3,5,7), Time(5,7,9)};//unable to understand the error??

    int n;
    cout << "Please enter size of an array: "<<endl;
    cin >> n;

    Time *arr4[n];
    for(int i = 0; i < n; i++)
    {
        arr4[i] = new Time();//creating array of objects dynamically after taking size input from the user
    }
    /*Time *arr4[2];
    arr4[0] = new Time[0];
    arr4[1] = new Time[1];*/

    for(int i = 0; i < n; i++)
    {
        arr4[i]->acceptTime();
    }

    for(int i = 0; i < n; i++)
    {
        arr4[i]->displayTime();
    }

    //below is the switch case(menu) to display the default time for the first time and it will display the updated time
    //if user opts to enter new time
    int choice;
    Time *arr5 = new Time();
    do
    {
      cout<<"Enter your choice: "<<endl;
      cout<< "0. Exit\n"<< "1. Enter new time\n"<< "2. Display time"<< endl;
      cin >> choice;
      switch (choice)
      {
        case 0:
            cout<<"Exiting program"<<endl;
            break;

        case 1:
            arr5->acceptTime();
            break;

        case 2:
            arr5->displayTime();
            break;
      
      default:
            cout<< "Invalid choice!!"<< endl;
            break;
      }
    } while (choice != 0);

    for(int i = 0; i < 3; i++)
    {
        delete arr2[i];
        arr2[i] = NULL;
    }

    for(int i = 0; i < n; i++)
    {
        delete arr4[i];
        arr4[i] = NULL;
    }

    delete[] arr5;
    arr5 = NULL;

    
}