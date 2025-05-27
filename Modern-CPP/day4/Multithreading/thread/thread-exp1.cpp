#include<iostream>
#include<thread>
using namespace std;

void fun()
{
    cout <<"fun called, thread-id :" << this_thread::get_id() << endl;
}

int main()
{
    cout <<"main execution started..., thread id :" << this_thread::get_id() << endl;
    //fun();
    //....
    thread th1(&fun);
    
    //..
    //..
    cout <<"main execution completed..." << endl;
    th1.join();
    return 0;
}
