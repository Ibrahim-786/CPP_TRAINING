#include<iostream>
using namespace std;
 
//struct CA
class CA
{
private:
    int a,b;
public:
    CA();
    CA(int x);
    CA(CA& );
    CA(int x, int y);
    ~CA();
    void input();
    void print();
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
	std::cout<<"CA 2 arg constructor.. "<<std::endl;	
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
 
void CA::print()
{
    cout << "a =" << this->a << ",b= " << this->b << endl;
}

CA::CA(CA& x):a(x.a),b(x.b)
{
	std::cout<<"copy constructor is called\n"<<std::endl;
}



//consumer code
int main()
{
    cout <<"size of CA:" << sizeof(CA) << endl;
    CA ob1(5) ;
    ob1.print();

    CA ob2(ob1); //   with demands copy constructor these line is prefered 
//
//    prefer copy constructor implementtation over the foll: approach
//    the foll : approach is more expensive than copy constructor call

    //CA ob2;  //call  default constructor
    
    //ob2 = ob1;  // will call compiler synthesized assignment function 
    ob2.print();

    return 0;
}

