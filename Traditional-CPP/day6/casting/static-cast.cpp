#include<iostream>
using namespace std;
/*
    - An example on static_cast.
    - Safe cast and compile-time cast
*/
class CA
{
public:
    void fun1() { cout << "CA fun1" << endl; }
};
class CB
{
public:
    void fun2() { cout << "CB fun2" << endl; }
};

class CC:public CA
{
    public:
    void fun2(){ cout << "fun2 of CC" <<endl;}



};

//consumer code
int main()
{
    CA* p = new(nothrow) CA;
    p->fun1();
    cout << "-------------" << endl;
   // CB* q = static_cast<CB*>(p); //trying to casting away un-related types - dangerous, and failed
    
    
    CC* q = static_cast<CC*>(p);
    q->fun2();

    q->fun1();
    delete p;
    return 0;
}

