#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA():a(0),b(0){cout <<"default constructor" << endl;}
    CA(int x):a(x),b(x){cout <<"one arg. constructor" << endl;}
    CA(int x, int y):a(x),b(y){cout <<"two arg. constructor" << endl;}
    CA(const CA& x):a(x.a),b(x.b){cout <<"CA copy constructor" << endl;}
};

//consumer code
int main()
{
    //Traditional approach
    //each element as part of the array on the heap would only call default constructor
    CA* p1 = new(nothrow) CA[5];
    delete [] p1;
    //Modern approach, we can provide parameters to each element of the array on heap
    CA* p2 = new(nothrow) CA[5]{{},{},{},{},{}};

    CA* p3 = new(nothrow) CA[5]{{1},{2,3},{5},{6},{}};
    delete [] p2;
    delete [] p3;
    return 0;
}
