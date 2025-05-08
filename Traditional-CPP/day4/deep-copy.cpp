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
};
/*
    - A lightweight wrapper class, that facilitates or manages HEAP for CA type instances,
      without the class library consumer having to use new/delete in their application code.
*/ 

 //CB IS A CONTAINER CLASS, where each instance of class CB, will hold a reference or a 
 //handle to another class instance type called CA. Also termed 'CB HAS-A CA'.
class CB   
{
private:
    CA* p;  //PIMPL MODEL - Pointer implementation model
public:
    //RAII -  Resource acquisition is initialization
    CB(int x=0, int y=0)
    {
        p = new(nothrow) CA(x,y);   //Acquiring a resource
    } 

    CB(const CB& x)
    {
	p= new(nothrow) CA(*(x.p));

    }

    CB& operator =(const CB& x)
    {
	    *(this->p) = *(x.p);
	    return *this;
    }


    ~CB()
    {
        delete this->p;     //Releasing the resource
    }   
    void print()
    {
        p->print();
    }
};


//***consumer code ***
int main()
{
    CB obj1(10,20);
    obj1.print();

   // CB obj2(30,40);
    CB obj2(obj1);  //copy construction
    obj2.print();

    CB obj3;
    obj3 =obj2;
    

    obj3.print();

    return 0;
}

