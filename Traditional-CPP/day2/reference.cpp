#include<iostream>


void swap1(int *ptr1, int *ptr2);
void swap2(int &ptr1, int &ptr2);






int main()
{



	int x =10, y=20;


	swap1(&x,&y);

	std::cout<<"x: "<<x<<"y: "<<y<<std::endl;

	swap2(x,y);


	std::cout<<"x: "<<x<<"y: "<<y<<std::endl;

	return 0;

}



void swap1(int *ptr1, int *ptr2)
{

	int temp =0;

	temp = *ptr1;

	*ptr1= *ptr2;

	*ptr2 = temp;

}


void swap2(int &ptr1, int &ptr2)
{

	int temp =0;

	temp = ptr1;

	ptr1= ptr2;

	ptr2 = temp;

}


