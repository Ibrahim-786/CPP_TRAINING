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
    th1.detach();
    //..
    //..
    cout <<"main execution completed..." << endl;
    if(th1.joinable())
    {
        th1.join();
        cout <<"thread joined" << endl;
    }
    else
    {
        cout <<"thread not joined" << endl;
    }
    
    return 0;
}
