#include<iostream>
using namespace std;
#pragma pack(1)
class CA
{
public:
	int a;
};
// virtual inheritance, only in the case of HYBRID inheritance model, u.nder
// the context the base class CA, is also called as VIRTUAL BASE CLASS.
class CB: virtual public CA
{
public:
	int b;
	/*  COMPILER WOULD ASSUME A DEFAULT CONSTRUCTOR
	CB():ptr(NULL)
	{

	}
	*/
};

class CC:  virtual public CA
{
public:
	int c;
	/*  COMPILER WOULD ASSUME A DEFAULT CONSTRUCTOR
	CC():ptr(NULL)
	{
		
	}
	*/
};

class CD :public CB, public CC
{
public:
	int d;
	/*  COMPILER WOULD ASSUME A DEFAULT CONSTRUCTOR
	CD():CB(), CC(), ptr(&CA::a)
	{
		
	}
	*/
};

//***********************
int main()
{
	cout <<"size of CD object" << sizeof(CD) << endl;
	CD obj1;
	obj1.a=100;

	return 0;
}
