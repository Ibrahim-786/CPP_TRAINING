#include<iostream>
#include<thread>
#include<boost/asio.hpp>

using namespace std;
using namespace boost;

int main()
{
    cout <<"Parent(main) thread id..." << this_thread::get_id() << endl;
    //create multiple io_service type instances
    asio::io_context service_ob1;
    asio::io_context service_ob2;

    //Lambda function, handler for the service object to process
    auto job_1 =[]()
    {
        cout << "job_1 lambda function, thread id..." << this_thread::get_id() << endl;
    };

    auto job_2 =[]()
    {
        cout << "job_2 lambda function, thread id..." << this_thread::get_id() << endl;
    };
    
    //now post both handlers into the respective service objects
    service_ob1.post(job_1);

    service_ob2.post(job_2);
    /*
        Boost 1.80 onwards

        post(service_ob1, job_1);
        post(service_ob2, job_2);

    */
    //execute the service
    service_ob1.run();
    service_ob2.run();
    return 0;
}
