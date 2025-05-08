#include<iostream>
using namespace std;
//LIBRARY VENDOR
class flute
{
public:
    void play(){cout <<"playing flute..." << endl;}
};
class Drums
{
public:
    void play(){cout <<"playing Drums..." << endl;}
};
class Piano
{
public:
    void play(){cout <<"playing Piano..." << endl;}
};
//A generic class supporting multiple typenames
template<typename T1, typename T2, typename T3> class compose
{
private:
    T1 ob1;
    T2 ob2;
    T3 ob3;
public:
    void compose_music();
};
template<typename T1, typename T2, typename T3> void compose<T1,T2,T3>::compose_music()
{
    ob1.play();
    ob2.play();
    ob3.play();
}
//consumer code
int main()
{
   compose<flute, Drums, Piano> music1;  //all 3 instuments

   music1.compose_music();

   cout<<"--------------------------------"<<endl;

   compose<flute, Drums, Drums> music2; //used only 2 instrumets

   music2.compose_music();

   cout<<"--------------------------"<<endl;

   compose<flute, flute, flute> music3; //used a single instrument

   music3.compose_music();

    return 0;
}
