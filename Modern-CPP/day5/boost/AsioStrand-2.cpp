#include<iostream>
#include<thread>
#include<functional>
#include<boost/asio.hpp>

using namespace std;
using namespace boost;

class CA
{
public:
    void fun1(){cout <<"CA fun1() called, thread-id =" << this_thread::get_id() << endl;}
    void fun2(){cout <<"CA fun2(int x) called, x= " <<  ", and thread-id =" << this_thread::get_id() << endl;}    
    void fun3(int x){ cout <<"CA::fun3(int) called, x=" << x <<", and thread-id =" << this_thread::get_id()<< endl;}
};

int main()
{
    asio::io_context iocontext;
    asio::io_context::strand strand(iocontext);
    CA ob;
   
    strand.post(std::bind(&CA::fun2, &ob));
    strand.post(std::bind(&CA::fun1, &ob));
    strand.post(std::bind(&CA::fun3, ob, 200));
    
    // thread th1([&iocontext](){iocontext.run();});
    // thread th2([&iocontext](){iocontext.run();});

    auto context_run = [&iocontext](){iocontext.run();};

    thread th1(context_run);
    thread th2(context_run);

    th1.join();
    th2.join();
    return 0;
}
