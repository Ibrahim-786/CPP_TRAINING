#include<iostream>

template<typename T1, typename T2> void add(T1 x, T2 y)
{

	std::cout<<"data type of x = "<<typeid(T1).name()<<std::endl;
	std::cout<<"data type of y = "<<typeid(T2).name()<<std::endl;

	std::cout<<"addition is : "<<x+y<<std::endl;
}


//Specialize the above generic function for `char` type
template<> void add(char x, char y) // non-generic function
{
	std::cout<<"characters cannot be added"<<std::endl;

}



int main()
{


	add(10,20);
	add(10.5,20.5);

	add('i','f');

	add(10.5, 20);

	return 0;
}






