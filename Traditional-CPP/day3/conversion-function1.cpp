#include<iostream>
using namespace std;
/*
    An example on conversion function.
    Overloading datatypes as functions is called conversion function.
    These functions do not take any known formal parameters.
    But, they must and should return a value of the type 'function-name'
*/
 
class CA
{
private:
    int a,b;
public:
    CA(int x, int y):a(x),b(y){ }
    operator int();
};
 
CA::operator int()
{
    cout <<"operator int called" << endl;
    return a+b;
}
 
//consumer code
int main()
{
    CA ob1(10,20);
    int x;
    //approach-1
    x = (int) ob1;   // x = ob1.operator int();
    cout <<"x =" << x << endl;
    //approach-2
    cout <<(int) ob1 << endl;   // cout << ob1.operator int() << endl;
    return 0;
}

