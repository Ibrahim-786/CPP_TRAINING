#include<iostream>
using namespace std;
/*
    - An example on assignment operator overloading
*/
 
class CA
{
private:
    int a,b;
public:
    CA(int=0, int=0);
    void print() const;
    CA& operator =(CA& x);
};
 
CA::CA(int x, int y):a(x),b(y){ }
void CA::print() const {cout <<"a=" << a <<",b=" << b << endl;}
 
CA& CA::operator=(CA& x)
{
    cout <<"operator = called" << endl;
    this->a = x.a;
    this->b = x.b;
    return *this;
}
 
//---consumer code
int main()
{
    CA ob1(10,20);
    CA result;
 
    //result = ob1;         //result.operator =(ob1);
   // result.print();
   CA ob2;
   result = ob2 = ob1;         //  result.operator =(ob2.operator =(ob1));
                               // result.operator =(ob2);
   ob2.print();
   result.print();
 
    return 0;
}

