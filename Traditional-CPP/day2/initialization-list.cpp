#include<iostream>
using namespace std;
 

// const data members only be in initialized never assigned 
//any business attempted on the data member in the bussiness logic phase of a constructor call is rather an assignment and not the initialization
class CA
{
private:
    int a;
    const int b;
public:
    CA();
    CA(int x);
    CA(int x, int y);
    ~CA();
    void input();
    void print();
};

CA::CA():b(0)
{
	std::cout<<"address of obj: "<<this<<std::endl;

	std::cout<<"CA deafult constructor.. "<<std::endl;	
	a=0;
	//b=0;
}

CA::CA(int x):b(0)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA one arg constructor.. "<<std::endl;	
	a=x;
	
}


CA::CA(int x, int y):b(y)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA two arg constructor.. "<<std::endl;	
	a=x;
	//b=y;
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
 //   cin >> this->a >> this->b;
}
 
void CA::print()
{
    cout << "a =" << this->a << ",b= " << this->b << endl;
}
 
//consumer code
int main()
{
    cout <<"size of CA:" << sizeof(CA) << endl;
    
    CA ob1 ;
    ob1.print();

   
    CA ob2(6) ;
    ob2.print();

    CA ob3(10,20) ;
    ob3.print();

    return 0;
}

