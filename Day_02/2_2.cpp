#include <iostream>
using namespace std;

class Tollbooth
{
    unsigned int paying_car_number;
    unsigned int non_paying_car_number;
    double money_collected;

    public:

    Tollbooth()
    {
        this->paying_car_number = 0;
        this->non_paying_car_number = 0;
        this->money_collected = 0;
    }

    void payingCar()
    {
        (this->paying_car_number)++;
        this->money_collected += 0.50;
    }

    void noPayCar()
    {
        (this->non_paying_car_number)++;

    }

    void printOnConsole()
    {
        cout<<"Total number of cars: "<<(this->paying_car_number + this->non_paying_car_number)<<endl;
        cout<<"Number of paying cars: "<<(this->paying_car_number)<<endl;
        cout<<"Number of non paying cars: "<<(this->non_paying_car_number)<<endl;
        cout<<"Total money collected from tollbooth: "<<(this->money_collected)<<endl;
    }

};

int main(void)
{
    Tollbooth t1;
    int choice;

    do
    {
        cout<<"0. Exit\n"<<"1. Show total number of cars and money collected\n"<<"2. Add paying car\n"<<"3. Add non paying car"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout << "Exiting program"<< endl;
                 break;
        
            case 1:
                t1.printOnConsole();
                break;

            case 2:
                t1.payingCar();
                break;

            case 3:
                t1.noPayCar();
                break;

            default:
                cout<< "Invalid choice"<< endl;
                break;
        }
    }while(choice != 0);

    return 0;
}
    