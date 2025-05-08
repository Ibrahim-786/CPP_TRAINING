#include<iostream>
using namespace std;
/*
    -An example on static data and static method as members of
    class template / generic class
*/
template<typename T> class CA
{
private:
    T a;
    static int b;
public:
    CA(T);
    void print() const;
    static void count(); //static method
};
/*
    Define memory for the static data member(s) in the global
    scope, immediately foll: the class declaration i.e. well before
    creating object instances.
*/
template<typename T> int CA<T>::b;   //defines memory for the static data member
//-------------------------
template<typename T> CA<T>::CA(T x):a(x){b=b+1;}
template<typename T> void CA<T>::print() const {cout <<"a ="<< a <<",b="<<b << endl;}
//deals only with static data members and no other.
template<typename T> void CA<T>::count(){ cout <<"Total objects:"<< b << endl;}
//consumer code
int main()
{
    CA<int> ob1(100),ob2(200);
    CA<float> ob3(34.12f);
    CA<double> ob4(45.20), ob5(80.12), ob6(99.32);
    //..
    CA<int>::count();
    CA<float>::count();
    CA<double>::count();
    return 0;
}
