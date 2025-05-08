#include<iostream>
using namespace std;
/*
    - An example on binary operator overloading
*/
 
class CA
{
private:
    int a,b;
public:
    CA()
    {
    	std::cout<<"default constructor \n";

    }
    CA(int, int=0);
    void print() const;
    //CA Add(const CA& x);
    CA(CA& x):a(x.a),b(x.b)
    {
	std::cout<<"copy constructor is called \n";
    }

    CA operator+(const CA& x);
    ~CA()
    {
	    cout<<"destructor is called\n";
    }
};
 
CA::CA(int x, int y):a(x),b(y){ }
void CA::print() const {cout <<"a=" << a <<",b=" << b << endl;}
 
/*
CA CA::Add(const CA& x)
{
    cout <<"Add called" << endl;
    CA temp;
    temp.a = this->a + x.a;
    temp.b = this->b + x.b;
    return temp;
}
 */

CA CA::operator+(const CA& x)
{
	cout<< "operator + called"<<endl;
	    CA temp;
    temp.a = this->a + x.a;
    temp.b = this->b + x.b;
    return temp;
}
//---consumer code
int main()
{
    CA ob1(10,20), ob2(30,40);
    CA result;
 //   result = ob1.Add(ob2);
    result = ob1.operator+(ob2);
    result = ob1 + ob2;   // result = ob1.operator+(ob2);
    CA ob3(50,60);
    result = ob1 + ob2 + ob3;   // result  = (ob1.operator +(ob2)).operator +(ob3);
    result.print();
    return 0;
}

