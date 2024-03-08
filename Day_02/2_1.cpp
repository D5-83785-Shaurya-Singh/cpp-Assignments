#include <iostream>
using namespace std;

class Box
{
    double length;
    double width;
    double height;

    public:

    Box()
    {
        this->length = 1.0;
        this->width = 1.0;
        this->height = 1.0;
    }

    void acceptDimension()
    {
        cout<<"Enter length"<<endl;
        cin>>this->length;
        cout<<"Enter width"<<endl;
        cin>>this->width;
        cout<<"Enter height"<<endl;
        cin>>this->height;
    }

    void calcVolume()
    {
        cout<<"Volume of the Box is "<<(this->length * this->width * this->height)<<endl;
    }
};

int main(void)
{
    Box b1;
    int choice;
    do
    {
        cout<<"0. Exit\n"<<"1. Display volume\n"<<"2. Enter new dimensions"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout << "Exiting program"<< endl;
                break;
            
            case 1:
                b1.calcVolume();
                break;
            case 2:
                b1.acceptDimension();
                break;

            default:
                cout<< "Invalid choice"<< endl;
                break;
        }

     }while(choice != 0);
}