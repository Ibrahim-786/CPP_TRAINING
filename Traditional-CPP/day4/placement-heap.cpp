#include<iostream>
#include<new>
using namespace std;

/*
    - Facilitate request for memory on PRE-DEFINED HEAP block
    - Ensure no single request is turned down
    - Also every request for memory is physically adjacent to the previous allocated location.
    - Flexibility to allocate memory for instances of heterogenous types on the HEAP BLOCK.
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
    char* Owner = (char*) malloc(BLOCK_SIZE);  //The actual owner of the HEAP BLOCK
    char* free_location = Owner;  //point to the starting block to begin with.

    //create an CA instance at the specified location (free_location) on the 
    //PRE-DEFINED BLOCK 
    CA* p1 = new(free_location) CA;
    //....

    //reset the pointer free_location to the available location for future allocations...
    free_location = free_location +sizeof(CA);

    //create an CB instance at the specified location (free_location) on the 
    //PRE-DEFINED BLOCK 
    CB* p2 = new(free_location) CB;
    //...

    //reset the pointer free_location to the available location for future allocations...
    free_location = free_location +sizeof(CB);

    //create an CC instance at the specified location (free_location) on the PRE-DEFINED BLOCK 
    CC* p3 = new(free_location) CC;
    //...

    //reset the pointer free_location to the available location for future allocations...
    free_location = free_location +sizeof(CC);

    //Suppose we wish to re-cycle or over-write on an already allocated_block, then...
    //We plan to re-cyle the memory owned by 'p1' i.e. the CA instance.
    
    //CB* p4 = new(p1) CB;  //This is OK only if the offset size of both CA and CB are same.
    
    /*
        - Execution of the above statement will only over-write the HEAP memory, but the 
          CA instance which perishes wouldn't implicitly invoke the destructor of the class.
        - Further, we cannot apply 'delete' with 'p1' handle, 'p1' is not the owner of that
          heap memory.
        - This is when, we need to explicitly call the destructor, before we over-write or 
          recycle a pre-defined location that hold's a class instance having a destructor method.
    */

   
        //A better approach...
        p1->CA::~CA();
        CB* p4 = new(p1) CB;
        p1 = NULL;

    //Before de-allocating the HEAP BLOCK, call the destructor explicitly with pointer handles
    //in the order that you prefer to.
    if(p1 != NULL)
        p1->CA::~CA();
    
     if(p2 != NULL)
        p2->CB::~CB();

     if(p3 != NULL)
        p3->CC::~CC();

     if(p4 != NULL)
        p4->CB::~CB();

    //De-allocate the PRE-DEFINED HEAP BLOCK
    free(Owner);
    return 0;
}


