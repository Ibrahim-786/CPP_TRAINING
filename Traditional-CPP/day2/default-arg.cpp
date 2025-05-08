#include<iostream>


using namespace std;


int add(int arg1=1,int arg2=1);


int add(int arg1, int arg2)
{

	return arg1+arg2;
}


int main(int argc,char *argv[])
{


	cout<<"no input: "<<add()<<endl;

	cout<<"2 input: "<<add(10,20)<<endl;

	cout<<"1 input: "<<add(10)<<endl;


	return 0;
}




