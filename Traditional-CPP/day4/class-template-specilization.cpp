#include<iostream>
#include<typeinfo>
using namespace std;
/*
    An example on generic class, supporting a single unknown datatype.
*/
template<typename T=double> class CA
{
private:
  T a,b;
public:
  CA(T);
  CA(T,T);
  ~CA();
  void Sum();
};
template<typename T> CA<T>::CA(T x):a(x),b(x)
{
    cout <<"CA<" <<typeid(T).name() <<"> one arg. constructor" << endl;
}
template<typename T> CA<T>::CA(T x, T y):a(x),b(y)
{
    cout <<"CA<" <<typeid(T).name() <<"> two arg. constructor" << endl;
}
template<typename T> CA<T>::~CA()
{
    cout <<"~CA<" <<typeid(T).name() <<"> destructor" << endl;
}
template<typename T> void CA<T>::Sum()
{
    cout <<"CA<" <<typeid(T).name() <<">::Sum called, sum =" << a+b << endl;
}


//specialize the complete generic class CA for  char type
//for specialize class defination of member function must be inside class itself
template<> class CA<char>
{

private:
    char a,b;
public:
    CA(char x,char y):a(x),b(y){ cout<<"CA-char specialized constructor "<<endl;}
    ~CA(){cout<<"CA-char specialized destructor "<<endl;}
    void print(){ cout<<"the 2 char are "<<a <<", and "<<b<<endl;}
};


//consumer code
int main()
{
    CA<int> ob1(10,20);

    ob1.Sum();

    CA<float> ob2(45.12f, 89.98f);

    ob2.Sum();

    CA<> ob3(567.21, 7889.23);

    ob3.Sum();

    cout<<"=-----------------------------------------"<<endl;

    CA<char> ob4('r','e');

   // ob4.Sum();
   ob4.print();
    return 0;
}
