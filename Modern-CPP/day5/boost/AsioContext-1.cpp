#include<iostream>
#include<boost/asio/io_context.hpp>

using namespace std;
using namespace boost;

int main()
{
    asio::io_context context;
    cout <<"main execution started..." << endl;
    context.run();
    cout <<"main execution completed..." << endl;
    return 0;
}
