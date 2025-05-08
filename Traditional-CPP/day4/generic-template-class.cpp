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
//consumer code
int main()
{
    CA<int> ob1(10,20);

    ob1.Sum();

    CA<float> ob2(45.12f, 89.98f);

    ob2.Sum();

    CA<> ob3(567.21, 7889.23);

    ob3.Sum();
   
    return 0;
}
