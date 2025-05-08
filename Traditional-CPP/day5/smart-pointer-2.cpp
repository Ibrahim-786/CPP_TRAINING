#include<iostream>
using namespace std;
//An example on shallow copy, where depending upon the compiler synthesized
//copy constructor and assignment function would be a bad-idea.
//Assumed to be a memory expensive class
class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){cout <<"CA constructor called" << endl;}  
    CA(const CA& x):a(x.a),b(x.b){cout <<"CA copy constructor called" << endl;}  
    CA& operator =(const CA& x)
    {
        cout <<"CA assignment function called" << endl;
        this->a = x.a;
        this->b = x.b;
        return *this;
    }
    ~CA(){cout <<"CA destructor called" << endl;}
    void print()const{cout <<"CA-print, a= " << a <<",b=" << b << endl;}
    void fun1(){cout <<"CA fun1 called" << endl;}
};
class CB
{
private:
    int a,b;
public:
    CB(int x=0, int y=0):a(x),b(y){cout <<"CB constructor called" << endl;}  
    CB(const CB& x):a(x.a),b(x.b){cout <<"CB copy constructor called" << endl;}  
    CB& operator =(const CB& x)
    {
        cout <<"CB assignment function called" << endl;
        this->a = x.a;
        this->b = x.b;
        return *this;
    }
    ~CB(){cout <<"CB destructor called" << endl;}
    void print()const{cout <<"CB-print, a= " << a <<",b=" << b << endl;}
    void fun1(){cout <<"CB fun1 called" << endl;}
};
//------------------------------------------------------------
template<typename T> class Smartpointer  
{
private:
    T* p;  //PIMPL MODEL - Pointer implementation model
public:
    //RAII -  Resource acquisition is initialization
    Smartpointer(int x=0, int y=0)
    {
        p = new(nothrow) T(x,y);   //Acquiring a resource
    }
    ~Smartpointer()
    {
        delete this->p;     //Releasing the resource
    }  
    //custom copy constructor - DEEP COPY avoids dangling pointer
    Smartpointer(const Smartpointer& x)
    {
        p = new(nothrow) T(*(x.p));  //will call CA copy constructor if any
    }
    //custom assignment function - DEEP ASSIGNMENT avoids memory leak
    Smartpointer& operator =(const Smartpointer& x)
    {
        *(this->p) = *(x.p);  //will call CA assignment function if any
        return *this;
    }
    T* operator ->()
    {
        cout <<"operator ->() called" << endl;
        return p;
    }
    T* operator &()
    {
        cout <<"operator & called" << endl;
        return p;
    }
    T& operator *()
    {
        cout <<"operator * called" << endl;
        return *p;
    }
};
//***consumer code ***
int main()
{
    Smartpointer<CA> ob1(10,20);
    ob1->print();
    ob1->fun1();
    cout <<"-----------------" << endl;
    Smartpointer<CB> ob2(30,40);
    Smartpointer<CB> ob3(ob2);
    ob2->print();
    ob3->print();
   
    return 0;
}
