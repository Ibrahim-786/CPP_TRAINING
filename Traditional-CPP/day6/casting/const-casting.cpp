#include<iostream>
using namespace std;
/*
    - An example const_cast, this casting operator tries to remove
    the constness of a const object.
*/
class CA
{
private:
    int a, b;
public:
    CA(int x=0, int y=0) :a(x), b(y) { }
    void input()   //non-const method
    {
        cout << "enter 2 nos." << endl;
        cin >> a >> b;
    }
    void print() const //const method
    { cout << "a =" << a << ",b=" << b << endl; }
};
//consumer code
int main()
{
    const CA* p = new(nothrow) CA(10, 20);
    //p->input();
    p->print();
    cout << "-----------" << endl;
    //cout remove the constness
    CA* q = const_cast<CA*>(p);
    q->input();
    q->print();
    delete p;
    return 0;
}
