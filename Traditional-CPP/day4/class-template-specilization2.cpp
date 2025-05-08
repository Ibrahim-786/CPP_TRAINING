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


//specialize the complete  class CA  to block char type
template<> class CA<char>
{

private:
    CA();
public:
   
};


/*partial specialization 
template<typename T> class CA<*T> 
{

};


consumer code
CA<int*> ob3;  3  partial
*/ 


/*size 
//template<typename T, size_t SIZE> class CA 
//{
    private:
        T arr[SIZE];

//};


consumer code
CA<int, 10> ob1;  
CA<float, 20> ob2; 

*/

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
