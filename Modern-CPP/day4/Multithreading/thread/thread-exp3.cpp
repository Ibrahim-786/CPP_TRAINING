#include<iostream>
#include<thread>
using namespace std;

void fun1(int x)
{
    cout <<"fun1 called, x= " << x << ", thread-id :" << this_thread::get_id() << endl;
}

void fun2(int& x)
{
    x+=100;
    cout <<"fun2 called, x= " << x << ", thread-id :" << this_thread::get_id() << endl;
}
int main()
{
    cout <<"main execution started..., thread id :" << this_thread::get_id() << endl;
   
    thread th1(&fun1, 10);
    int z=200;
    thread th2(&fun2, std::ref(z));
    
    cout <<"inside main, z = " << z << endl;
    cout <<"main execution completed..." << endl;
    
    th1.join();
    th2.join();
    
    return 0;
}
