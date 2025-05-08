#include<iostream>
#include<new>
using namespace std;
// preventing heap based object
class CA
{
private:
	void *operator new(size_t size) { return 0; }
	void operator delete(void *pv) { }
	void * operator new[](size_t size) { return 0; }
	void operator delete[](void *pv) { }
public:
	//.....
};

int main()
{
	CA obj1;
	//CA *p = new CA;
}
