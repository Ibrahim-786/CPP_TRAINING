#include<iostream>
using namespace std;
/*
    Function pointers, callbacks with class member functions
    - non-static and
    - static method(s)
*/
class CA
{
public:
    //non-static member functions
    void fun1(){cout <<"CA fun1 called" << endl;}
    void fun2(int x){cout <<"CA fun2 called" << endl;}
    //static method
    static void static_fun(){cout <<"static_fun called" << endl;}
};
//consumer code
int main()
{
    CA ob1;
    //function pointer to hold address of class function not gloabl function
    void (CA::*fp) () = &CA::fun1;
//.* and :: can't be overloaded  just a heads up no specific to these .cpp file
    (ob1.*fp)();   
    cout<<"----------------------------"<<endl;

    void(CA::*fp2) (int) = &CA::fun2;

    CA* p = new (nothrow) CA;

    (p->*fp2)(100);

    delete p;

    cout<<"------------------"<<endl;

    void (*fp3)() = &CA::static_fun;

    (*fp3)();
    return 0;
}
