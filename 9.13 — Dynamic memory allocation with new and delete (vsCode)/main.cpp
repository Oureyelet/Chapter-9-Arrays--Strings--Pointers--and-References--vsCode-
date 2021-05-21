#include <iostream>

int main()
{
    std::cout << "Hello World\n";

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "The need for dynamic memory allocation" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int array[1000000];

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Dynamically allocating single variables" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator:
    new int;// dynamically allocate an integer (and discard the result)

    //Most often, we’ll assign the return value to our own pointer variable 
    //so we can access the allocated memory later.
    int* ptr{ new int };//dynamically allocate an int and assign the address to ptr so we can access it later

    //We can then perform indirection through the pointer to access the memory:
    *ptr = 7;// assign value of 7 to allocated memory

    /*
    If it wasn’t before, it should now be clear at least one case in which pointers are useful. 
    Without a pointer to hold the address of the memory that was just allocated, 
    we’d have no way to access the memory that was just allocated for us!
    */

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "How does dynamic memory allocation work?" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Initializing a dynamically allocated variable" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //When you dynamically allocate a variable, you can also initialize it 
    //via direct initialization or uniform initialization (in C++11):

    int* ptr2 { new int (7) };// use direct initialization
    int* ptr3 { new int { 8 } };// use uniform initialization

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Deleting single variables" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    // assume ptr has previously been allocated with operator new
    delete ptr3;// return the memory pointed to by ptr to the operating system

    ptr3 = 0;// set ptr to be a null pointer (use nullptr instead of 0 in C++11)

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "What does it mean to delete memory?" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    /*
    The delete operator does not actually delete anything. It simply returns the memory being 
    pointed to back to the operating system. The operating system is then free to reassign that 
    memory to another application (or to this application again later).

    Although it looks like we’re deleting a variable, this is not the case! 
    The pointer variable still has the same scope as before, and can be assigned a 
    new value just like any other variable.
    */

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Dangling pointers" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int* ptr4{ new int };// dynamically allocate an integer
    *ptr4 = 7;// put a value in that memory location

    delete ptr4;// return the memory to the operating system.  ptr is now a dangling pointer.

    std::cout << *ptr4 << '\n';// Indirection through a dangling pointer will cause undefined behavior

    delete ptr4;// trying to deallocate the memory again will also lead to undefined behavior.

    /*
    Best practice

    Set deleted pointers to 0 (or nullptr in C++11) unless they are 
    going out of scope immediately afterward.
    */

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Operator new can fail" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int* value = new (std::nothrow) int; // value will be set to a null pointer if the integer allocation fails

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Null pointers and dynamic memory allocation" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    

    

    return 0;
}

