#include<iostream>
#include<thread>
#include<boost/asio.hpp>

using namespace std;
using namespace boost;

int main()
{
    cout <<"Parent(main) thread id..." << this_thread::get_id() << endl;
    //create an io_context type instance
    asio::io_context service_ob;

    //Lambda function, handler for the service object to process
    auto job_1 =[]()
    {
        cout << "job_1 lambda function, thread id..." << this_thread::get_id() << endl;
    };

    auto job_2 =[]()
    {
        cout << "job_2 lambda function, thread id..." << this_thread::get_id() << endl;
    };
    
    //now post the lambda's to the service object
    service_ob.post(job_1);
    service_ob.post(job_2);

    //execute the service
    service_ob.run();
    return 0;
}
