#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T> class bloat
{
private:
	int a, b;
	T c,d;
public:
	bloat(int x, int y, T i, T j):a(x),b(y),c(i), d(j) {     }

	void fun1()    // does business with both generic as well as non-generic data
	{
		//cout << __FUNCDNAME__ << endl;
		cout <<"fun1<"<<typeid(T).name() <<">" << endl;
		cout <<"a = " << a <<",b=" << b << endl;
		cout <<"c = " << c <<",d = " << d << endl;
	}
	
	void fun2()   //doing business only with non-generic data
	{
		//cout << __FUNCDNAME__ << endl;
		cout <<"fun2<"<<typeid(T).name() <<">" << endl;
		cout <<"a = " << a <<",b=" << b << endl;
	}
};
//-------------consumer code -----------------
int main()
{
	bloat<float> obj1(10,20, 45.12f, 56.32f);
	obj1.fun1();
	obj1.fun2();
	cout <<"---------------------"<<endl;
	bloat<double> obj2(300,400, 98.34, 67.29);
	obj2.fun1();
	obj2.fun2();

	return 0;
}
