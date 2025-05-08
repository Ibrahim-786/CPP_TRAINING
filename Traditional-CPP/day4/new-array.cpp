#include<iostream>
#include<cstdlib>
using namespace std;
/*
An example on malloc/free & new/delete
prefer malloc/free functions for primitive type data and C structs.
prefer new/delete functions for class objects. The 'new' operator function is capable of
    implicitly calling suitable constructor method and 'delete' operator function is capable of
    implicitly invoking destructor method.
*/
class CA
{
private:
    int a,b;
public:
    CA();
    CA(int);
    CA(int, int);
    CA(const CA &);
    ~CA();
    void input();
    void print() const;   //const method
};
CA::CA():a(0), b(0)   //iniitializer list, an instruction that would be added in the prolog phase          
{   cout <<"CA default constructor called "  << endl;   }
CA::CA(int x):a(x), b(x)
{   cout <<"CA one arg. constructor" << endl; }
CA::CA(int x, int y):a(x), b(y)
{   cout <<"CA two arg. constructor" << endl;   }
CA::~CA()              
{
    cout <<"CA destructor"  << endl;
}
CA::CA(const CA &x): a(x.a),b(x.b)
{  cout <<"CA copy constructor" << endl;  }
void CA::input()  
{
    cout <<"enter 2 nos" << endl;
    cin >> this->a >> this->b;
}
void CA::print() const    
{
    cout << "a =" << this->a <<",b=" << this->b << endl;
}
//-------------- class consumer------------------
int main()
{
    //create an array of 5 CA objects on the heap
    //CA* p = new(nothrow)CA[5];

    CA* p = new (nothrow) CA[5]{{},{100},{20,30},{40},{50,60}};

    delete [] p;
    return 0;
}
