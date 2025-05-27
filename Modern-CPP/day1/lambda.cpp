#include<iostream>
using namespace std;

//An example on lambda functions

int main()
{
    //define a lambda without a handle and invoke the same at the 
    //point of definition itself

    []()
    {
        cout <<"lambda without a handle called" << endl;
    }();

    //Lambda expressions with handle
    auto lm1 =[]()
    {
        cout <<"lambda with handle lm1 called" << endl;
    };

    auto lm2 = [](int x)
    {
        cout <<"lambda with handle lm2 called, x =" << x << endl;
    };

    auto lm3 = [](int x) ->int
    {
        cout << __FUNCTION__ << endl;
        cout << __PRETTY_FUNCTION__ << endl;
        cout <<"lambda with handle lm3 called,.." << endl;
        return x*x;
    };

    //consume the above lambda's
    lm1();
    lm2(100);
    cout << lm3(30);

    return 0;
}
