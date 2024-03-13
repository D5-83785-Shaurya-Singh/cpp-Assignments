#include <iostream>
using namespace std;

class Product //base class
{
    int id;
    string title;
    float price;

    public:

        Product()
        {
            this->id = 1;
            this->title = "default";
            this->price = 100;
        }

        Product(int id, string title, float price)
        {
            this->id = id;
            this->title = title;
            this->price = price;
        }

        int getPrice() 
        {
            return this->price;
        }

        void setPrice(int price)
        {
            this->price = price;
        }

        virtual void accept()
        {
            cout << "Enter product id: " << endl;
            cin >> this->id;
            cout << "Enter product title: " << endl;
            cin >> this->title;
            cout << "Enter product price: " << endl;
            cin >> this->price;
        }

        virtual void display()
        {
            cout << "Product id: " << this->id << endl;
            cout << "Product title: " << this->title << endl;
            cout << "Price of the product is " << this->price << endl;
        }

        virtual float calculateDiscountedPrice() = 0; //pure virtual function()
       


};

class Book : public Product //derived
{
    string author;

    public:

        Book()
        {
            this->author = "default";
        }

        Book(string author)
        {
            this->author = author;
        }

        string getAuthor()
        {
            return this->author;
        }

        void setAuthor(string author)
        {
            this->author = author;
        }

        void accept() //overridden function
        {
            Product::accept();
            cout << "Enter author name: " << endl;
            cin >> this->author;
        }

        float calculateDiscountedPrice()
        {
           float x = this->getPrice();
           float y = x * 0.1;
           x = (x - y);
           return x;
        }

        void display() //overridden function
        {
            Product::display();
            cout << "Author name is " << this->author << endl;
            /*float x = this->calculateDiscountedPrice();
            cout << "Discounted book price: " << endl;
            cout << x;*/
            
        }

        

};

class Tape : public Product //derived class
{
    string artist;

    public:
        Tape()
        {
            this->artist = "default";
        }

        Tape(string artist)
        {
            this->artist = artist;
        }

          void accept() //overridden function
        {
            Product::accept();
            cout << "Enter artist name: " << endl;
            cin >> this->artist;
        }

        float calculateDiscountedPrice()
        {
           float x = this->getPrice();
           float y = x * 0.05;
           x = (x - y);
           return x;
        }

        void display() //overridden function
        {
            Product::display();
            cout << "Artist name is " << this->artist << endl;
            /*float x = this->calculateDiscountedPrice();
            cout << "Discounted tape price: " << endl;
            cout << x;*/
        }
        
};

//enum Products {BOOK = 1, TAPE = 2};

int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add Tape" << endl;
    cout << "3. Display books" << endl;
    cout << "4. Display tape" << endl;
    cout << "5. Display all products" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    return choice;
}

int main(void)
{
    static float final_bill = 0;
    int choice, size, count = 0;
    cout << "Please enter size of array: " << endl;
    cin >> size;
    Product *ptr[size];
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1:
                if(count < size)
                {
                    ptr[count] = new Book(); //upcasting
                    ptr[count]->accept();
                    count++;
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                break;

            case 2:
                if(count < size)
                {
                    ptr[count] = new Tape(); //upcasting
                    ptr[count]->accept();
                    count++;
                }
                else
                {
                    cout << "Array is full!!" << endl;
                }
                break;
                
            case 3: 
                for(int i = 0; i < count; i++)
                {
                    if(typeid(*ptr[i]) == typeid(Book))
                    {
                        ptr[i]->display();
                        float book_price;
                        book_price = ptr[i]->calculateDiscountedPrice();
                        final_bill += book_price;
                        cout << "Discounted price for book is " << book_price << endl; 
                    }   

                }
                break;

            case 4:
                for(int i = 0; i < count; i++)
                {
                    if(typeid(*ptr[i]) == typeid(Tape))
                    {
                        ptr[i]->display();
                        float tape_price;
                        tape_price = ptr[i]->calculateDiscountedPrice();
                        final_bill += tape_price;
                        cout << "Discounted price for tape is " << tape_price << endl;
                    }
                }
                break;

            case 5:
                for(int i = 0; i < count; i++)
                {
                    ptr[i]->display();
                    float p = ptr[i]->calculateDiscountedPrice();
                    cout << "Discounted price is " << p << endl;
                }
                break;

            default:
                cout << "Invalid choice!!" << endl;
                break;
        }
    }

    cout << "Total bill for the products you purchased is " << final_bill << endl;

    for(int i = 0; i < count; i++)
    {
        delete ptr[i];
    }
    
    cout << "===============Thank you=====================" << endl;
    return 0;
    
}
   