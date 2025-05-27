#include<iostream>
using namespace std;

//Lambda expression - capture the outer-scope elements by value

int main()
{
    int a =10,b=20;

    auto lm = [=]() mutable
    {
        a+=10;   //captured as value so cannot be modified and accessed
        b+=10;
        cout <<"inside lambda.. a= " << a <<",b=" << b << endl;
    };

    cout <<"inside main, before calling lambda.. a= " << a <<",b=" << b << endl;
    lm();
    cout <<"inside main, after calling lambda.. a= " << a <<",b=" << b << endl;
    lm();
    return 0;
}
