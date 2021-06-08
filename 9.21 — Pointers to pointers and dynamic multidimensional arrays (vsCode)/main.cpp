#include <iostream>

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers to pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    //This lesson is optional, for advanced readers who want to learn more about C++. 
    //No future lessons build on this lesson.

    //A normal pointer to an int is declared using a single asterisk:
    int *ptr_info;// pointer to an int, one asterisk

    //A pointer to a pointer to an int is declared using two asterisks:

    int **ptrptr_info;// pointer to a pointer to an int, two asterisks

    //A pointer to a pointer works just like a normal pointer:

    int value { 5 };

    int *ptr { &value };
    std::cout << *ptr << '\n';// Indirection through pointer to int to get int value


    int **ptrptr { &ptr };
    std::cout << **ptrptr << '\n'; // first indirection to get pointer to int, second indirection to get int value


    int ***ptrptrptr { &ptrptr };
    std::cout << ***ptrptrptr << '\n'; // xD xD

    //However, a pointer to a pointer can be set to null:
    int **ptrptr = nullptr; // use 0 instead prior to C++11

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays of pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pointers to pointers have a few uses. The most common use is 
    to dynamically allocate an array of pointers:
    */
    int **array = new int*[10];// allocate an array of 10 int pointers
    //(This works just like a standard dynamically allocated array, except the array 
    //elements are of type “pointer to integer” instead of integer.)

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Two-dimensional dynamically allocated arrays" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    //Another common use for pointers to pointers is to facilitate dynamically allocated multidimensional arrays

    //Unlike a two dimensional fixed array, which can easily be declared like this:
    int array[5][3];

    /*
    Dynamically allocating a two-dimensional array is a little more challenging.
    There are two possible solutions here. If the rightmost array dimension is 
    a compile-time constant, you can do this:
    */
    int (*array)[5] = new int[10][5];

    //or:

    // In C++11 or newer, this is a good place to use automatic type deduction:
    auto array_2 = new int[5][10]; // so much simpler!

    // !! FOR SEE MORE GO TO: https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing a pointer by address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    /*
    We recommend avoiding using pointers to pointers unless no other options are available, because 
    they’re complicated to use and potentially dangerous. It’s easy enough to perform indirection 
    through a null or dangling pointer with normal pointers — it’s doubly easy with a pointer to 
    a pointer since you have to do a double-indirection to get to the underlying value!
    */
    return 0;
}