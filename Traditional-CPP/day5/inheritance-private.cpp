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

class CB:private CA    //DERIVED class
{
private:
	int a, b;
	//void CA::input(){ }
	//void CA::print(){ }
public:
	void input()
	{
		CA::input();
		cout << "CB-input, enter 2 nos.." << endl;
		cin >> a >> b;
	}
	void print() 
	{ 
		CA::print();
		cout << "CB-print, a:" << a << ",b:" << b << endl; 
	}
};
//****CONSUMER CODE******
int main()
{
	cout << "size of CB:" << sizeof(CB) << endl;
	CB obj1;
	obj1.input();
	obj1.print();

	return 0;
}

