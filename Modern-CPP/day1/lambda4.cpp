#include<iostream>
#include<functional>
using namespace std;



function<int(int)> fib = [](int x)
{
   return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
};


int main()
{
    /* LOCAL LAMBDA WHOSE SCOPE IS main */
    // define a recursive lambda
    //auto fib = [&fib](int x)

   

    cout << fib(10) << endl;


    return 0;
}
