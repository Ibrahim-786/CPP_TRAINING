#include<iostream>
using namespace std;

class CA
{
//private:
protected:
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

protected:
//int a, b;
private:
	int a, b;

public:

	//void CA::input(){ }
	//void CA::print(){ }
	void input()
	{

		cout << "CB-input, enter 4 nos.." << endl;
		cin >> CA::a >> CA::b;
        cin>>CB::a >> CB::b;

	}
	void print() 
	{ 
		cout<<"CB- print "<<endl;
		cout << "a:" << CA::a << ",b:" << CA::b << endl; 
        cout << "a:" << CB::a << ",b:" << CB::b << endl; 
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

