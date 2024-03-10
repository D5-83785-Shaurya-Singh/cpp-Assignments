#include <iostream>
using namespace std;

#define SIZE 5

class Stack
{
    int size;
    int *arr;
    int top;

    public:

        Stack()
        {
            this->top = -1;
            this->size = SIZE;
            arr = new int[size];
        }

        Stack(int n)
        {
            top = -1;
            this->size = n;
            arr = new int[size];
            
        }

        void push(int ele)
        {
            if(!(isFull()))
            {
                top++;
                arr[top] = ele;
            }
            
        }

        void pop()
        {
            top--;
        }

        int peek()
        {
            return (arr[top]);
        }

        bool isEmpty()
        {
           return (top == -1);
        }

        bool isFull()
        {
            return (top == size-1);
        }

        void printStack()
        {
            if(isEmpty())
                cout<< "Nothing to print!!\n"<<"Stack is empty!!\n";
            else
                {
                    for(int i = 0; i <= top; i++)
                    {
                        cout << arr[i] << "  ";
                    }
                    cout << "\n" << endl;
                }
        }

    
        
};


int main(void)
{
    Stack s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);

    Stack s3;
    for(int i = 0 ; i < SIZE; i++)
    {
        int x;
        cout << "Enter element to push: " << endl;
        cin >> x;
        s3.push(x);
    }
    s3.printStack();


    int size;
    cout << "Enter size of dynamic array: "<< endl;
    cin >> size;

    Stack s2(size);
    int choice;

    do
    {
        cout << "Enter your choice" << endl;
        cout << "0.Exit\n" << "1.Push an element onto the stack\n" << "2.Pop an element from the stack" << endl;
        cout << "3.Display the last inserted element\n" << "4.Print all the elements present in stack\n" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                cout << "Exiting the program!!" << endl;
                break;

            case 1:
                if(s2.isFull())
                {
                    cout << "Stack is full!!"<< endl;
                }
                else
                {
                    int x;
                    cout << "Enter element to push: " << endl;
                    cin >> x;
                    s2.push(x);
                }
                break;

            case 2:
                if(s2.isEmpty())
                {
                    cout << "Nothing to pop!! " << "Stack is empty!!" << endl;
                }
                else
                {
                    s2.pop();
                }
                break;

            case 3:
                if(s2.isEmpty())
                {
                    cout << "Nothing to peek!! " << "Stack is empty!!" << endl;
                }
                else
                {
                    int y = s2.peek();
                    cout << y << endl;
                }
                break;

            case 4:
                if(s2.isEmpty())
                {
                    cout << "Nothing to print!! " << "Stack is empty!!" << endl;
                }
                else
                {
                    s2.printStack();

                }
                break;

            default:
                cout << "Inalid choice!!" << endl;
                break;
        }
    } while (choice != 0);
    return 0;

}

/*Stack arr1[3] = {Stack(), Stack(), Stack()};
    for(int i = 0; i < 3; i++)
    {
        int x;
        cout << "Enter element to push"<< endl;
        cin >> x;
        arr1[i].push(x);
    }

    int y = arr1->peek();
    cout << y << endl;

    arr1->printStack();
    
     for(int i = 0; i < 3; i++)
    {
        arr1[i].pop();
    }

    arr1->printStack();//elements poppped so it will not print anything
    */
