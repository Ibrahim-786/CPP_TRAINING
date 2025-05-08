#include<iostream>
using namespace std;

//An example constructor and destructor behaviours with regard to inheritance 
//and derived class instances.
/*
	- Whenever we happen to create a derived class object, this derived instance will only call
	  the derived class constructor implicitly, the base constructor will not get implicitly, we
	  have to explicitly make a call to base the class constructor.
	- And so the is the destructor behaviour.

	It is in this light we also say that, constructors/destructor methods are NOT DERIVABLE

	Note: It is our bound duty as derived class programmers to call the appropriate base
	      constructors, if we don't the compiler presumes or assumes that we wished to call
		  the base class default constructor, and thereby on our behalf the compiler will
		  add those explicit call statements to the derived constructors initialization list
		  on our behalf.

*/
class CA
{
private:
	int a, b;
public:
	CA() :a(0), b(0) { cout << "CA default constructor" << endl; }
	CA(int x) :a(x), b(x) { cout << "CA one arg. constructor" << endl; }
	CA(int x, int y) :a(x), b(y) { cout << "CA two arg. constructor" << endl; }
	CA(const CA& x) :a(x.a), b(x.b) { cout << "CA copy constructor" << endl; }
	~CA() { cout << "CA destructor" << endl; }
};
class CB:public CA     // CB  IS-A CA
{
private:
	int a, b;
public:
	CB():CA(),a(0), b(0) { cout << "CB default constructor" << endl; }

	CB(int x):CA(x),  a(x), b(x) { cout << "CB one arg. constructor" << endl; }

	CB(int x, int y):CA(x,y),a(x), b(y) { cout << "CB two arg. constructor" << endl; }

	CB(const CB& x) : CA(x),a(x.a), b(x.b) { cout << "CB copy constructor" << endl; }
	
	~CB() 
	{ 
		cout << "CB destructor" << endl;
 //   CA::~CA();   //--> added by the compiler in the EPILOG on our behalf
    }
	
};

//***class consumers****
int main()
{
	CB obj1(100,200);
    
//	cout << "-----------------" << endl;
//	CB obj2(obj1);
	return 0;
}
