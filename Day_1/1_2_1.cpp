#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    public:

        void initDate()
        {
            this->day = 6;
            this->month = 3;
            this->year = 2024;
        }

        void printDateOnConsole()
        {
            cout << "Day: "<< this->day<< endl;
            cout << "Month: "<< this->month<< endl;
            cout << "Year: "<< this->year<< endl;

        }

        void acceptDateFromConsole()
        {
            cout << "Enter day: "<< endl;
            cin >> this->day;
            cout << "Enter month: "<< endl;
            cin >> this->month;
            cout << "Enter year: "<< endl;
            cin >> this->year;
        }

        bool isLeapYear()
        {
            if((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0))
            {
                cout << "It's a leap year"<< endl;
                return true;
            }

            else
            {
                cout<< "It's not a leap year"<< endl;
                return false;
            }
        }

};

int main(void)
{
    struct Date d1;
    int choice;
    do
    {
        cout << "0. Exit\n"<< "1. Initialize date\n"<< "2. Print date:\n"<< "3. Enter new date:\n" << "4. Check if it is a leap year"<< endl;
        cin >> choice;
        switch (choice)
        {
         case 0:
            cout << "Exiting program"<< endl;
            break;

        case 1:
            d1.initDate();
            break;
        
        case 2:
            d1.printDateOnConsole();
            break;

        case 3:
            d1.acceptDateFromConsole();
            break;

        case 4:
            //bool val;
            d1.isLeapYear();
            break;
        
        default:
            cout<< "Invalid choice"<< endl;
            break;
        }

    } while (choice != 0);
    
    return 0;
    
}