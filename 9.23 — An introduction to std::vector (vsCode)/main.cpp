#include <iostream>
#include <vector>

void printLenght(const std::vector<int>& array)
{
    std::cout << "The lenght is: " << array.size() << '\n';
}

int main()
{
    std::cout << "Hello World" << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An introduction to std::vector" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    /*
    the C++ standard library provides functionality that makes working with 
    dynamic arrays safer and easier. This functionality is named std::vector.
    */

    /*
    Introduced in C++03, std::vector provides dynamic array functionality that handles its own 
    memory management. This means you can create arrays that have their length set at run-time, 
    without having to explicitly allocate and deallocate memory using new and delete. 
    std::vector lives in the <vector> header.

    Declaring a std::vector is simple:
    */
    // no need to specify length at the declaration
    std::vector<int> array;
    std::vector<int> array2 = { 9, 7, 5, 3, 1 };// use initializer list to initialize array (Before C++11)
    std::vector<int> array3 { 9, 7, 5, 3, 1 };// use uniform initialization to initialize array

    // as with std::array, the type can be omitted since C++17
    std::vector array4 { 9, 7, 5, 3, 1 };// deduced to std::vector<int>
    std::vector array5 { 9.4, 7.2, 5.7, 3.1, 1.1 };// deduced to std::vector<double

    //As of C++11, you can also assign values to a std::vector using an initializer-list:

    array4 = { 0, 1, 2, 3, 4 }; // okay, array length is now 5
    array3 = { 9, 8, 7 }; // okay, array length is now 3
    //In this case, the vector will self-resize to match the number of elements provided.


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Self-cleanup prevents memory leaks" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Vectors remember their length" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    printLenght(array3);

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Resizing a vector" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    std::vector array6 { 0, 1, 2, 3 };
    array6.resize(5); // set size to 5

    std::cout << "The lenght is: " << array6.size() << '\n';

    for (auto& array : array6)
    {
        std::cout << array << ' ';
    }
    std::cout << std::endl;
    //Vectors may be resized to be smaller.

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Compacting bools" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////




    return 0;
}