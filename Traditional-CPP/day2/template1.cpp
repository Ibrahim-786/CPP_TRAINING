#include<iostream>

template<typename T> void add(T x, T y)
{

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

	return 0;
}






