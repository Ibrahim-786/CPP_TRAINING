#include<iostream>
using namespace std;

//Traditional approach of resolving return type issues...

//LIBRARY VENDOR

template<typename T1, typename T2> T1 Add(T1 a, T2 b)
{
    return a+b;
}

//LIBRARY CONSUMER
int main()
{
    float x;
    x = Add(12.45f, 100);
    cout <<"x =" << x << endl;
    x = Add(100, 12.45f);
    cout <<"x =" << x << endl;
    return 0;
}
