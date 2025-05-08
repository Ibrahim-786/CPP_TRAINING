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
        ls1.push_back(i);
    }
    /*
        Create an iterator instance that can help iterate a list model holding
        integer values, and initialize to point to the first node in the list.
    */
    list<int>::iterator itr = ls1.begin();
    while (itr != ls1.end())
    {
        cout << *itr << ",";
        itr++;
    }
    cout << endl;
    return 0;
}
