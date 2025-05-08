#include<iostream>
using namespace std;
 
class CA
{
    private:

    	int a,b;
    
    public:
    void input()
    {
        cout <<"enter 2 nos." << endl;
        cin >> a >> b;
    }
 
    void print()
    {
        cout <<"a =" << a <<",b= " << b << endl;
    }
};
 
//consumer code
int main()
{
    cout <<"size of CA:" << sizeof(CA) << endl;
    CA ob1;
    ob1.input();
    ob1.print();
    return 0;
}

