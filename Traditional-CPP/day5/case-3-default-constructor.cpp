#include<iostream>
using namespace std;

//An example on default constructor assumption by the compiler, if in-case the programmer
//does not provide any.

class CA
{
public:
   CA(){ cout<<"CA constructor got called";}  //default constructor is provided for 'CA'
};

class CB:public CA  // CB IS-A CA
{
private:
   //...
public:
   //No constructor is provided for the derived class CB, yet compiler
   //will assume one for CB, as the base class CA has a default constructor 
};

int main()
{

    //no object no creation of constructor
 //   CB obj1;
 CB obj1;
    return 0;
}
