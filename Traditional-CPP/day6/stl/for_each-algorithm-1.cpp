#include<iostream>
#include<list>
#include<algorithm>
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

    void operator()(CA& x); //FUNCTOR
};


void CA::operator()(CA& x){cout <<"a ="<< x.a <<",b="<< x.b << endl; }

CA::CA(int x, int y):a(x),b(y){}
CA::CA(const CA& x):a(x.a),b(x.b){}
CA::~CA(){}
void CA::print() const{cout <<"a ="<< a <<",b="<< b << endl;}
//class consumer code
void Print(CA& ob)
{
    ob.print();
}
int main()
{
    list<CA> ls1;
    //populate the list
   
    for(int i = 1;i<=5;i++)

    {
        ls1.push_back(CA(i, i+10));
    }
    cout <<"Approach-1"<<endl;
    list<CA>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        itr->print();        // itr.operator ->()
        itr ++;
    }
    cout <<endl;
    cout <<"-------Approach 2-------------" << endl;
    for_each(ls1.begin(), ls1.end(), Print);
                                   //, Print(object_from ls1);

    cout <<"-------Approach 3-------------" << endl;
    CA ob1;
    for_each(ls1.begin(), ls1.end(), ob1);
                                //, ob1.operator()(object_from ls1);
    return 0;
}
