#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> ls1;
    cout << "initial size of the list " << ls1.size() << endl;
    // populate the list container
    for (int i = 1; i <= 10; i++)
    {
        ls1.push_front(i);
    }
    /*
        Create an iterator instance that can help iterate a list model holding
        integer values, and initialize to point to the first node in the list.
    */
    cout<<"content of list before sorting"<<endl;
    list<int>::iterator itr = ls1.begin();
    while (itr != ls1.end())
    {
        cout << *itr << ",";
        itr++;
    }
    cout << endl;

    //sort the list contents
    ls1.sort();
    cout <<"Contents of the list after sorting.."<<endl;
    itr = ls1.begin();
    while (itr != ls1.end())
    {
        cout << *itr << ",";   // cout << itr.operator *();
        itr++;                 // itr.operator ++(int);
    }

    return 0;
}
