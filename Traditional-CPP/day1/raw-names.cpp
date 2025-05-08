#include<iostream>
#include<typeinfo>
using namespace std;
/*
    An example on raw names, by using the 'typeid' operator
    function from 'typeinfo' library.
*/
int main()
{
    /* microsoft C++ compiler
    cout <<"Raw name for char is " << typeid(char).raw_name() << endl;
    */
    cout <<"Raw name for char is " << typeid(char).name() << endl;
    cout <<"Raw name for int is " << typeid(int).name() << endl;
    cout <<"Raw name for float is " << typeid(float).name() << endl;
    cout <<"Raw name for double is " << typeid(double).name() << endl;
    cout <<"Raw name for bool is " << typeid(bool).name() << endl;
    cout <<"Raw name for void is " << typeid(void).name() << endl;
    return 0;
}
