#include<iostream>
#include<thread>
#include<boost/asio.hpp>

using namespace std;
using namespace boost;


void Even()
{
    for(int i=2;i<=100; i+=2)
    {
        cout <<"Even ...:" << i << ", its id =" << this_thread::get_id() << endl;
    }
}

void Odd()
{
    for(int i=1;i<=100; i+=2)
    {
        cout <<"Odd ...:" << i << ", its id =" << this_thread::get_id() << endl;
    }
}

int main()
{
    asio::io_context iocontext;
    asio::io_context::strand strand_(iocontext);

    strand_.post(Odd);
    strand_.post(Even);

    auto context_run = [&iocontext]()
    {
        iocontext.run();
    };

    
    thread th1(context_run);
    thread th2(context_run);
  
    th1.join();
    th2.join();

    return 0;
}
