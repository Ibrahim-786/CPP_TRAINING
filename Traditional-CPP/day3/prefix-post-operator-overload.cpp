#include<iostream>
using namespace std;
/*
    - An example on unary operator overloading
*/
 
class CA
{
private:
    int a,b;
public:
    CA(int=0, int=0);
    void print() const;
   CA& operator ++();   //prefix
   CA operator ++(int);  //postfix
};
 
CA::CA(int x, int y):a(x),b(y){ }
void CA::print() const {cout <<"a=" << a <<",b=" << b << endl;}
 
CA& CA::operator++()
{
    cout <<"prefix ++ called" << endl;
    ++ this->a;
    ++ this->b;
    return *this;
}
 
CA CA::operator++(int)
{
    cout <<"postfix ++ called" << endl;
    CA temp(*this);
    this->a ++;
    this->b ++;
    return temp;
}
 
//---consumer code
int main()
{
    CA ob1(10,20), ob2(10,20);
    CA prefix, postfix;
    prefix = ++ob1;         // prefix = ob1.operator ++();
    ob1.print();
    prefix.print();
    cout <<"============" << endl;
    postfix = ob2++;        // postfix = ob2.operator ++(int);
    ob2.print();
    postfix.print();
   
 
    return 0;
}

