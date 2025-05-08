#include<iostream>
using namespace std;
 
//template<typename T1, typename T2> T1 Add(T1 x, T2 y)

template<typename T1, typename T2, typename T3> T3 Add(T1 x, T2 y)
{
    return x+y;
}
 
//consumer code
int main()
{
    float x;
 //   x = Add(12.34f, 100);
    x = Add<float,int,float>(12.34f, 100);
    cout <<"x =" << x << endl;
    cout <<"---------------" << endl;
    x = Add<int,float,float>(100, 12.34f);
    cout <<"x =" << x << endl;
    return 0;
}

