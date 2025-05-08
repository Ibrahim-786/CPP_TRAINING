#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class student
{
private:
   //...
   int id;
   int marks;
public:
    student(int x=0, int y=0):id(x),marks(y){ }
    void print() { cout <<"id = " << id << ",marks = " << marks << endl; }
    int getmarks()
    {
        return marks;
    }
    bool operator()(student &s1, student &s2)
    {
        bool result = (s1.getmarks() > s2.getmarks())?true:false;
        return result;
    }
};
int main()
{
    vector<student> v1;
    student obj1;
    for(int i=1;i<=5;i++)
        v1.push_back(student(i, i+50));
    cout <<"contents of the vector before sorting..." << endl;
    vector<student>::iterator itr = v1.begin();
    while(itr != v1.end())
    {
        itr->print();
        itr++;
    }
    sort(v1.begin(), v1.end(), obj1);   // (v1.begin(), v1.end(), student());
                            //, obj1.operator()(first_obj_from_v1, second_obj_from_v1)
    cout <<"contents of the vector after sorting..." << endl;
    itr = v1.begin();
    while(itr != v1.end())
    {
        (*itr).print();
        itr++;
    }
    return 0;
}
