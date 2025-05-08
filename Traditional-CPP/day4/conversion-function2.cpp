#include<iostream>
using namespace std;
/*
    Example that illustrates custom data-types being overloaded
    as conversion functions.
*/
class rupees; //forward declaration
class dollars
{
private:
    double d;
public:
    dollars(double =0);
    void Amount();
    operator rupees();
};

dollars::dollars(double x):d(x){ }
void dollars::Amount() {cout <<"amount in dollars :"<< d << endl;}
/*
    We are defining the conversion function 'operator rupees' after
    the 'rupees' class declaration.
*/

class rupees
{
private:
    double r;
public:
    rupees(double=0);
    void Amount();
    operator dollars();
};

rupees::rupees(double x):r(x){ }
void rupees::Amount(){cout <<"amount in rupees :"<< r << endl;}
rupees::operator dollars()
{
    return r/83.0;   // (or) return dollars(r/83.0);
}

dollars::operator rupees()
{
    return d*83.0;  // (or) return rupees(d*83.0);
}

//consumer code
int main()
{
    dollars d1(100), d2;
    rupees r1, r2(21239);
    r1 = (rupees) d1;     // r1 = d1.operator rupees();
    d1.Amount();
    r1.Amount();
    cout <<"----------------" << endl;
    d2 = (dollars) r2;   // d2 = r2.operator dollars();
    d2.Amount();
    r2.Amount();
    
    return 0;
}
