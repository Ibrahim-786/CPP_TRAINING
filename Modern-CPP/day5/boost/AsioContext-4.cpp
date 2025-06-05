#include<iostream>
#include<thread>
#include<boost/asio.hpp>

using namespace std;
using namespace boost;

void fun()
{
    asio::io_context service_ob2;

     auto job_2 =[]()
    {
        cout <<"Running on service_ob2..." << endl;
        cout << "job_2 lambda function, thread id..." << this_thread::get_id() << endl;
    };

    service_ob2.post(job_2);
    service_ob2.run();
}

int main()
{
    cout <<"Parent(main) thread id..." << this_thread::get_id() << endl;
    //create multiple io_service type instances
    asio::io_context service_ob1;
    

    //Lambda function, handler for the service object to process
    auto job_1 =[]()
    {
        cout <<"Running on service_ob1..." << endl;
        cout << "job_1 lambda function, thread id..." << this_thread::get_id() << endl;
    };

   
    
    //now post both handlers into the respective service objects
    service_ob1.post(job_1);

    thread th1(fun);

    //execute the service
    service_ob1.run();
    th1.join();
    return 0;
}
