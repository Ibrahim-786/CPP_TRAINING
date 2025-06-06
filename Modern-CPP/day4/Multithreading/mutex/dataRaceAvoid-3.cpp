#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
//C++17 use scoped_lock to lock multiple mutexs all at once, thus avoiding dead-locks
class CA
{
private:
	//...
	mutex m1, m2;
public:
	void fun1(int x)
	{
		/*
		lock(m1, m2);
		lock_guard<mutex> guard1(m1, adopt_lock);
		lock_guard<mutex> guard2(m2, adopt_lock);
		*/
		scoped_lock<mutex, mutex> lock(m1, m2);  //C++17
		cout << "CA-fun1 called " << x << endl;
	}
	void fun2(int x)
	{
		/*
		lock(m1, m2);
		lock_guard<mutex> guard2(m2, adopt_lock);
		lock_guard<mutex> guard1(m1, adopt_lock);
		*/
		scoped_lock<mutex, mutex> lock(m1, m2);   //C++17
		cout << "CA-fun2 called " << x << endl;
	}
};

void process(CA& ob)
{
	for (int i = 100; i <= 2000; i++)
	{
		ob.fun1(i);
	}
}

int main()
{
	CA obj1;
	thread th1(process, ref(obj1));
	for (int i = 1; i <= 999; i++)
	{
		obj1.fun2(i);
	}
	th1.join();

	return 0;
}
