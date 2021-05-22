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

    //std::cout << *ptr4 << '\n';// Indirection through a dangling pointer will cause undefined behavior

    //delete ptr4;// trying to deallocate the memory again will also lead to undefined behavior.

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
    /*
    In the context of dynamic memory allocation, a null pointer basically says 
    “no memory has been allocated to this pointer”. This allows us to do things like 
    conditionally allocate memory:
    */
    // If ptr isn't already allocated, allocate it
    if(!ptr4)
        ptr4 = new int;
    //Deleting a null pointer has no effect. Thus, there is no need for the following:
    if(ptr4)
        delete ptr4;
    //Instead, you can just write:
    //delete ptr4;
    //If ptr is non-null, the dynamically allocated variable will be deleted. 
    //If it is null, nothing will happen.
    
    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Memory leaks" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int value2{ 5 };
    int* ptr5{ new int{} };// allocate memory
    ptr5 = &value2;// old address lost, memory leak results

    //This can be fixed by deleting the pointer before reassigning it:

    int value3{ 5 };
    int* ptr6{ new int{} };// allocate memory
    delete ptr6;// return memory back to operating system
    ptr6 = &value3;// old address lost, memory leak results

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    /*
    Operators new and delete allow us to dynamically allocate single variables for our programs.

    Dynamically allocated memory has dynamic duration and will stay allocated until you deallocate 
    it or the program terminates.

    Be careful not to perform indirection through dangling or null pointers.

    In the next lesson, we’ll take a look at using new and delete to allocate and delete arrays.
    */

    return 0;
}

