#include <iostream>
using namespace std;

int fact(int n)  //function definition to find factorial of a given number
{
    int i, res = 1;

    for(i = n; i > 0; i--)
    {
        res = res * i;
    }
    return res;
}

int main(void)
{
    int n, x = 10;
    try  //try block
    {
        {
            cout << "Please enter the number to find its factorial " << endl;
            cin >> n;
            if (n < 0) //throw condition
            {
                throw x; //throw jump statement
            }
            int f = fact(n);

            cout << "Factorial of the given number is " << f << endl;
        }
    }
    catch(int x) //matching catch block 
    {
        cout << "Value cannot be less than zero!! " << endl;
        cout << "Inside catch block " << endl;
    }
    return 0;
     
}