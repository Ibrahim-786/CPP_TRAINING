#include<iostream>
using namespace std;
 
//struct CA
class CA
{
private:
    int a,b;
public:
//    CA();
    CA(int x);
    CA(int x, int y);
    ~CA();
    void input();
    void print();
};

/*CA::CA()
{
	std::cout<<"address of obj: "<<this<<std::endl;

	std::cout<<"CA deafult constructor.. "<<std::endl;	
	a=0;
	b=0;
}*/

CA::CA(int x)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA one arg constructor.. "<<std::endl;	
	a=x;
	b=0;
}


CA::CA(int x, int y)
{

	std::cout<<"address of obj: "<<this<<std::endl;
	std::cout<<"CA two arg constructor.. "<<std::endl;	
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
 
//consumer codeZ
int main()
{
    cout <<"size of CA:" << sizeof(CA) << endl;
    CA ob1(5) ;
    ob1.print();

   
    CA ob2(6,7) ;
    ob2.print();

    CA ob3(10) ;
    ob3.print();

    CA ob4(10,20) ;
    ob4.print();
    return 0;
}

