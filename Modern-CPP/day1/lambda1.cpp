#include<iostream>
using namespace std;

//Lambda expression - capture the outer-scope elements by reference

int main()
{
    int a =10,b=20;

    auto lm = [&]()
    {
        a+=10;
        b+=10;
        cout <<"inside lambda.. a= " << a <<",b=" << b << endl;
    };

    cout <<"inside main, before calling lambda.. a= " << a <<",b=" << b << endl;
    lm();
    cout <<"inside main, after calling lambda.. a= " << a <<",b=" << b << endl;
    return 0;
}
