#include <iostream>
#include <string>
#include <cstddef> // std::size_t

using namespace std;

void message(string);

int main()
{  
    message( "Hello World" );

    /*
    To allocate an array dynamically, we use the array form of new and delete 
    (often called new[] and delete[]):
    */
    std::cout << "Enter a positive integer: ";
    std::size_t lenght{};
    std::cin >> lenght;

    int* array{ new int[lenght]{} };// use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << lenght << '\n';

    array[0] = 5;// set element 0 to value 5
    delete[] array;// use array delete to deallocate array
    // we don't need to set array to nullptr/0 here because it's going to go out of 
    //scope immediately after this anyway

    /*
    Because we are allocating an array, C++ knows that it should use the array version 
    of new instead of the scalar version of new. Essentially, the new[] operator is called, 
    even though the [] isn’t placed next to the new keyword.
    */

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Dynamically deleting arrays" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////" << '\n';
    std::cout << "Dynamic arrays are almost identical to fixed arrays" << '\n';
    std::cout << "////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;    

    //////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing dynamically allocated arrays" << '\n';
    std::cout << "////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl; 
    //starting with C++11, it’s now possible to initialize dynamic arrays using initializer lists!
    int fixedArray[]{ 9, 7, 5, 3, 100 };// initialize a fixed array before C++11
    int* dinamicArray{ new int[5]{ 9, 7, 5, 3, 100 } };// initialize a dynamic array since C++11
    // To prevent writing the type twice, we can use auto. This is often done for types with long names.
    delete[] dinamicArray;

    //////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////" << '\n';
    std::cout << "Resizing arrays" << '\n';
    std::cout << "////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    /*
    Dynamically allocating an array allows you to set the array length at the time of allocation. 
    However, C++ does not provide a built-in way to resize an array that has already been allocated. 
    It is possible to work around this limitation by dynamically allocating a new array, 
    copying the elements over, and deleting the old array.
    */

    //////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    /*
    Question #1

    Write a program that:
    * Asks the user how many names they wish to enter.
    * Dynamically allocates a std::string array.
    * Asks the user to enter each name.
    * Calls std::sort to sort the names (See 9.4 -- Sorting an array using selection sort 
    * and 9.11 -- Pointer arithmetic and array indexing)
    * Prints the sorted list of names.

    std::string supports comparing strings via the comparison operators < and >. 
    You don’t need to implement string comparison by hand.

    Your output should match this:

    How many names would you like to enter? 5
    Enter name #1: Jason
    Enter name #2: Mark
    Enter name #3: Alex
    Enter name #4: Chris
    Enter name #5: John

    Here is your sorted list:
    Name #1: Alex
    Name #2: Chris
    Name #3: Jason
    Name #4: John
    Name #5: Mark

    A reminder

    You can use std::getline() to read in names that contain spaces.

    A reminder

    To use std::sort() with a pointer to an array, calculate begin and end manually

    1
	
    std::sort(array, array + arrayLength);
    */

    return 0;
}

void message(std::string x)
{
    std::cout << x << '\n';
}