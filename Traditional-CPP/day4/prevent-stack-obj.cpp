#include<iostream>
using namespace std;

class CA
{
private:
	CA() { cout <<"CA constructor called" << endl;}
public:
	static CA* create_heapinst()
	{
		return new CA;
	}
};

int main()
{
	CA *p = CA::create_heapinst();
	//CA obj;
	//CA* q = new CA;

	delete p;
}
