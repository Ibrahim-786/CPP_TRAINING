#include<iostream>
#include<list>
using namespace std;
class CA
{
private:
    int a,b;
public:
    CA(int=0, int=0);
    CA(const CA& x);
    ~CA();
    void print() const;
};
CA::CA(int x, int y):a(x),b(y){cout <<"CA parameterized constructor"<<endl;}
CA::CA(const CA& x):a(x.a),b(x.b){cout <<"CA copy constructor"<<endl;}
CA::~CA(){cout <<"CA destructor"<<endl;}
void CA::print() const{cout <<"a ="<< a <<",b="<< b << endl;}
//consumer code
int main()
{
    list<CA> ls1;
    //populate the list
   
    for(int i = 1;i<=5;i++)
    {
        ls1.push_back(CA(i, i+10));
    }
    list<CA>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        itr->print();        // itr.operator ->()
        itr ++;
    }
    cout <<endl;
    cout <<"--------------------" << endl;
    return 0;
}
