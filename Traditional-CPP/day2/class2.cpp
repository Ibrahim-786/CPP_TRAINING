#include<iostream>
using namespace std;
 
class CA
{
    private:

    	int a,b;
    
    public:
    void input()//void input(CA* const this)
    {
        cout <<"enter 2 nos." << endl;
        cin >> this->a >> this->b;
    }
 
    void print() //void print(CA* const this)
    {
        cout <<"a =" << this->a <<",b= " << this->b << endl;
    }
};
 
//consumer code
int main()
{
    cout <<"size of CA:" << sizeof(CA) << endl;
    CA ob1;
    ob1.input(); // CA::input(&obj1);
    ob1.print(); // CA::print(&obj1)
    return 0;
}

