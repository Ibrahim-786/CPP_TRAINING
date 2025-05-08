#include<iostream>
using namespace std;
/*
    A example on global function pointers, that facilitate callbacks.
*/
//programmer-1
void Add(int x, int y){cout <<"Add called, sum =" << x+y << endl;}
void Diff(int x, int y){cout <<"Diff called, difference =" << x-y << endl;}
//programmer-2

typedef void (*FP) (int, int);
//void Compute(void(*ff)(int, int), int x, int y)
void Compute(FP ff, int x, int y)
{
    cout <<"Compute business started..." << endl;
    (*ff)(x,y);
    cout <<"Compute business completed..." << endl;
}
//programmer-3
int main()
{
    //Approach-1    
    void(*fp)(int, int) = &Add;
    Compute(fp, 100,200);
    cout <<"-------------" << endl;
    //Approach-3
    Compute(&Diff, 200, 100);
    return 0;
}
