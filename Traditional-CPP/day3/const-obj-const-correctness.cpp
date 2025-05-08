#include<iostream>
using namespace std;
 
//struct CA
class CA
{
private:
    int a,b;
public:
    	CA();
	explicit    CA(int x);
	CA(const CA& );
    	CA(int x, int y);
    	~CA();
    	void input();  // void input(CA* const this )
    	void print() const ; // void print(const CA* this)
};


CA::CA()
{
	std::cout<<"address of obj: "<<this<<std::endl;

	std::cout<<"CA deafult constructor.. "<<std::endl;	
	a=0;
	b=0;
}

CA::CA(int x)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA 1 arg constructor.. "<<std::endl;	
	a=x;
	b=0;
}


CA::CA(int x, int y)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA deafult constructor.. "<<std::endl;	
	a=x;
	b=y;
}

CA::~CA()
{
	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA Destructor is called.. "<<std::endl;
}
 
//place definitions outside the class body
void CA::input()
{
    cout << "enter 2 nos." << endl;
    cin >> this->a >> this->b;
}
 
void CA::print() const
{
    cout << "a =" << this->a << ",b= " << this->b << endl;
}

CA::CA(const CA& x):a(x.a),b(x.b)
{
	std::cout<<"copy constructor is called\n"<<std::endl;
}


//const object can only call const member function
//non const object can call both const and non const member function 
//consumer code
int main()
{

	/*

	//scenario -1
	CA ob1(10,20);
	ob1.input();
	ob1.print();

*/

	//scenario -2
	const CA ob1(10,20);
//	ob1.input();
	ob1.print();

	CA ob2(ob1);
	ob2.print();

    return 0;
}

