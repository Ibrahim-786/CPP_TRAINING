#include<iostream>


using namespace std;



class CA
{


	private:
		int a;
		static int b;

	public:
		CA(int=0);
		void print() const; 
		static void count();  // void count()   no these pointer in static member function
		//void count();      // void count(CA* const this)
};

//define memory for static data member in global scope

int CA::b ;



CA::CA(int x):a(x)
{
	b=b+1;
}

void CA::print() const
{
	cout<< "a=   " <<a << "b=   "<<b<<endl;
}

void CA::count()
{

//	a=5;  // error
	b=b;  // ok   // only static member
	cout<<"total objs: "<< b <<endl;
}


int main()
{


    cout <<"size of CA object :" << sizeof(CA) << endl;
    CA ob1(100), ob2(200), ob3(300);
 //   ob1.print();
   // ob2.print();
    //ob3.print();
    

    ob1.count();
    ob2.count();
    ob3.count();

    CA::count();
    return 0;

}

