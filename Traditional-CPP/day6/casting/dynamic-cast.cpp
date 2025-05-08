#include<iostream>
using namespace std;
class shape
{
public:
    virtual void draw() = 0;
    ~shape(){}
};
class circle :public shape
{
public:
    void draw() { }
};
class rectangle :public shape
{
public:
    void draw() { }
};
//consumer code
void FindShape(shape* p)
{
    // circle* c = static_cast<circle*>(p);
    // rectangle* r = static_cast<rectangle*>(p);
    circle* c = dynamic_cast<circle*>(p);
    rectangle* r = dynamic_cast<rectangle*>(p);
    if (c != NULL)
        cout << "p is pointing to CIRCLE" << endl;
    if (r != NULL)
        cout << "p is pointing to RECTANGLE" << endl;
}
int main()
{
    circle* c = new(nothrow) circle;
    FindShape(c);
    delete c;
    return 0;
}
