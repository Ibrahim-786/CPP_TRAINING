#include<iostream>
#include<functional>
using namespace std;




int main()
{
    /* LOCAL LAMBDA WHOSE SCOPE IS main */
    // define a recursive lambda
    //auto fib = [&fib](int x)

    function<int(int)> fib = [&fib](int x)
     {
        return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
     };

    cout << fib(10) << endl;


    return 0;
}
