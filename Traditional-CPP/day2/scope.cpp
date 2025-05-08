#include<iostream>
using namespace std;
 
int z = 100;  //global variable
 
class CA
{
private:
    int z;  //class data member
public:
   void print();
};
 
void CA::print()
{
   int z = 200; // functions local variable
   // code for printing all 3 z's
   cout <<"Global z = " << ::z << endl;
   cout <<"class data member z = " << this->z << endl;
   cout <<"member functions local variable z = " << z << endl;
}
 
//consumer code
int main()
{
    CA ob;
    ob.print();
    return 0;
}

