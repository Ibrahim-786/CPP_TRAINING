#include<iostream>
using namespace std;
//stream operator overloading.
 
class CA
{

    //anywhere inside the class
    //friend void operator >>(istream& input, CA& ob);
    //friend void operator <<(ostream& print, CA& ob);

    friend istream& operator >>(istream& input, CA& ob);
    friend ostream& operator <<(ostream& print, CA& ob);
private:
    int a,b;


 public:
    // friend void operator >>(istream& input, CA& ob);
    // friend void operator <<(ostream& print, CA& ob);
 
};
 
//global functions
/*void operator >>(istream& input, CA& ob)
{
    cout <<"operator >> called"<<endl;
    input >> ob.a >> ob.b;
}
 
void operator <<(ostream& print, CA& ob)
{
    //cout <<"operator << called"<< endl;
	print <<"a = " << ob.a <<" ,b=" << ob.b<<endl;
}*/
 
istream& operator >>(istream& input, CA& ob)
{
    cout <<"operator >> called"<<endl;
    input >> ob.a >> ob.b;
    return input;
}
 
ostream& operator <<(ostream& print, CA& ob)
{
    //cout <<"operator << called"<< endl;
	print <<"a = " << ob.a <<" ,b=" << ob.b<<endl;
	return print;
}
//consumer code
int main()
{
    CA ob1;
//    cin >> ob1;         //operator >>(cin, ob1);
  //  cout << ob1;        // operator <<(cout, ob1);
    
    
  CA ob2 ;
    cin >>ob1 >>ob2;  // operator >>(operator >>(cin, ob1), ob2);
    		      // operator >>(void,ob2);
		      // operator >> (cin,ob2);
    cout<<ob1<<ob2;   //operator <<(operator <<(cout, ob1), ob2);
                      // operator <<(void,ob2)
		      // operator <<(cout, ob2);
    
    
    return 0;
}

