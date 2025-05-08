#include<iostream>
#include<map>
#include<string>
using namespace std;


//map is a tree structure
int main()
{
    map<int, string> m;           //m[1] = "john"  ===> m[key] = "value"
    m[1] = "john";           // (m.operator [](1)).operator =("john");      
    m[2] = "peter";
    m[3] = "simon";
    m[4] = "Haval";     //If a duplicate already exists, replace the old with the new
    //If a duplicate already exisits, then retain the old and ignore the new
    m.insert(pair<int, string> (5,"clara"));
    //create an iterator to traverse the map container
    map<int, string>::iterator itr= m.begin();
   
    while(itr != m.end())
    {
        cout <<itr->first << "\t" << itr->second << endl;
                     //itr->first     ===> (itr.operator ->())->first;
        itr++;
    }
    int key;
    cout <<"enter the key "<<endl;
    cin >> key;
   
    itr = m.find(key);
    if(itr != m.end())
    {
        cout << itr->second << endl;
    }
    else
    {
        cout <<"not found"<<endl;
    }
    return 0;
}
