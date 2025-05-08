#include<iostream>
using namespace std;

//An example default constructor assumption by the compiler, if in-case the programmer
//does not provide any.

class CA
{
public:
   //CA(){ }  //default constructor is provided for 'CA' no constructor
    CA () {}
};

class CB
{
private:
   CA ob;    // CB HAS-A CA  [containment]
public:
   //No constructor is provided for the container class CB, yet compiler
   //will assume one, as the contained data-member, an object belongs to a class
   //having a default constructor.   
};

int main()
{
    CB obj1;

    cout<<sizeof(obj1);
    return 0;
}
