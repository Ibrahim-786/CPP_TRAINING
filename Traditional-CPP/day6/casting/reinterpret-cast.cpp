#include<iostream>
using namespace std;
/*
    - An example on reinterpret_cast.
    - Use it only if you are sure about the outcome.
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
//consumer code
int main()
{
    CA* p = new(nothrow) CA;
    p->fun1();
    cout << "-------------" << endl;
    CB* q = reinterpret_cast<CB*>(p); //casting away un-related types - dangerous
    q->fun2();
    delete p;
    return 0;
}
