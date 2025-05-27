#include<iostream>
using namespace std;

/*
template <class > -> older ways 
template <typename > -> new ways

*/


//compile time  polymorphism
template <typename  T> void add(T a, T b)
{
    T c = a + b;
    cout << c << endl;
    
}

/*
void add(int a, int b)   // _z3Addii
{
    int c = a + b;
    cout << c << endl;
}

void add(float a, float b)  // _z3addff
{
    float c = a + b;
    cout << c << endl;
}

void add(double a, double b)  // _z3adddd
{
    double c = a + b;
    cout << c << endl;
}
{
    double c = a + b;
    cout << c << endl;
}
*/

//consumer code
int main()
{
    add(10, 20);
    add(10.5, 20.5);
    add(10.5f, 20.5f);
    add('A', 'B');
    return 0;
}
