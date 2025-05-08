#include<iostream>
using namespace std;
typedef void(*CFP)();
class MyFunc   // FUNCTION CLASS
{
private:
    CFP fp;    //void(*fp)();
public:
    MyFunc(CFP ff):fp(ff){ }
    void Set(CFP ff)
    {
        fp = ff;
    }
    void Call()
    {
        (*fp)();
    }
    void operator()()  // function operatOR overloading   [functor]
    {
        (*fp)();
    }
};
//consumer code
void fun1() {cout <<"Fun1 called" << endl;}
void fun2() {cout <<"Fun2 called" << endl;}
int main()
{
    MyFunc ob1(&fun1);  // ob1 is a function object
 //   ob1.Call();
    ob1();    // ob1.operator()();
    cout <<"----------------" << endl;
    ob1.Set(&fun2);
    ob1();
   
    return 0;
}
