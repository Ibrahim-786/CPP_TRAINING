#include<iostream>
using namespace std;
//An example on conversion function - overloading 'bool' type
class Data
{
private:
  int* p;
public:
  Data():p(NULL){ }
  Data(int* q):p(q){ }
  ~Data()
  {
    if(p != NULL)
        delete(p);
  }
  void print() { cout <<"value pointed to =" << *p << endl;}

  operator bool()
  {
    cout <<"operator bool called" << endl;
    if(p != NULL)
        return true;
    else
        return false;
  }
};

//consumer code
int main()
{
    Data d1;
    Data d2(new(nothrow) int(100));
    if(d1)                 // if(d1.operator bool())
        d1.print();
    else
        cout <<"d1 handle is invalid"<<endl;
    if(d2)
        d2.print();
    else    
        cout <<"d2 handle is invalid"<<endl;
    return 0;
}

