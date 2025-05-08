#include<iostream>
using namespace std;

class CA
{
private:
	int a, b;
public:
	void input()
	{
		cout << "CA-input, enter 2 nos.." << endl;
		cin >> a >> b;
	}
	void print() { cout << "CA-print, a:" << a << ",b:" << b << endl; }
};

class CB:public CA    //DERIVED class
{
private:
	int a, b;

public:

	//void CA::input(){ }
	//void CA::print(){ }
	void input()
	{

		cout << "CB-input, enter 2 nos.." << endl;
		cin >> a >> b;
	}
	void print() 
	{ 
		
		cout << "CB-print, a:" << a << ",b:" << b << endl; 
	}
};
//****CONSUMER CODE******
int main()
{
	cout << "size of CB:" << sizeof(CB) << endl;
	CB obj1;
	obj1.CA::input();
    obj1.CB::input();
	obj1.CA::print();
    obj1.CB::print();

	return 0;
}

