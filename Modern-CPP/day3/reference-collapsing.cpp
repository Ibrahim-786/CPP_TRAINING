#include<iostream>
using namespace std;

//Overcome the issues faced by the traditional C++ programmers with regard 
//to generic programming.

template<typename T1,typename T2> void Wrapper(T1&& x, T2&& y)
{
    cout << "x = " << x <<endl;
    cout << "y = " << y << endl;
}

//***consumer code *********
int main()
{
    int a=10;
    float b=20.23f;
    Wrapper(a,b);       //wrapper(int &, float&) ==> wrapper(int& &&, float& &&) -> wrapper(int&, float&)
 
    Wrapper(100,56.21f);   //wrapper(int &&, float &&) -> wrapper(int&& &&, float&& &&) -> wrapper(int&&, float&&) -> wrapper(int , float)
    
    Wrapper(a, 56.21f);   
   
    Wrapper(100, b);      
  
    return 0;
}
