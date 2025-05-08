#include<iostream>
#include<new>
using namespace std;

/*
    - Facilitate request for memory on PRE-DEFINED HEAP block
    - Ensure no single request is turned down
    - Also every request for memory is physically adjacent to the previous allocated location.
    - Flexibility to allocate memory for instances of heterogenous types on the STACK BLOCK.
*/

class CA
{
public:
    CA(){cout <<"CA constructor" << endl;}
    ~CA(){cout <<"CA destructor called" << endl;}
};

class CB
{
public:
    CB(){cout <<"CB constructor" << endl;}
    ~CB(){cout <<"CB destructor called" << endl;}
};

class CC
{
public:
    CC(){cout <<"CC constructor" << endl;}
    ~CC(){cout <<"CC destructor called" << endl;}
};

const int BLOCK_SIZE=200;

int main()
{
    /*
        - Traditionally an array when defined, it's memory allocation is compile time
          and on the STACK area of the process memory.
        - Moreover, this memory by default will only help us hold homogenous types of values...
        - With 'placement new' operator we can over-come this hurdle.
    */
    char Owner[BLOCK_SIZE]; //The actual owner of the STACK BLOCK

    char* free_location = Owner;  //point to the starting block to begin with.

    //create an CA instance at the specified location (free_location) on the PRE-DEFINED BLOCK 
    CA& p1 = *new(free_location + 0) CA;  //Direct referencing the value created on the STACK BLOCK
    //....

    //create an CB instance at the specified location (free_location) on the PRE-DEFINED BLOCK 
    CB& p2 = *new(&p1 + 1) CB;
    //...

    //create an CC instance at the specified location (free_location) on the PRE-DEFINED BLOCK 
    CC& p3 = *new(&p2 + 1) CC;
    //...

     //Suppose we wish to re-cycle or over-write on an already allocated_block, then...
    //We plan to re-cyle the memory owned by 'p1' i.e. the CA instance.
    
    //CB& p4 = *new(&p1 + 0) CB;  //This is OK only if the offset size of both CA and CB are same.
    
    /*
        - Execution of the above statement will only over-write the STACK memory, but the 
          CA instance which perishes wouldn't implicitly invoke the destructor of the class.
        - Further, we our-selves cannot de-allocate memory on the STACK area. 
        - A de-allocation of STACK memory would only happen when the function to which the
          array instance 'Owner' is local terminates.
        - thereby we need to explicitly call the destructor, before we over-write or 
          recycle a pre-defined location that hold's a class instance having a destructor method.
    */
        //A better approach...
        p1.CA::~CA();
        CB& p4 = *new(&p1+0) CB;
   
    //Just before the array is about to be de-allocate, call the destructor explicitly with  
    //the help of valid alias instances...
        p2.CB::~CB();
    
        p3.CC::~CC();

        p4.CB::~CB();
    return 0;
}


