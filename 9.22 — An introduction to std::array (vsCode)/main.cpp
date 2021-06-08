#include <iostream>
#include <array>

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An introduction to std::array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::array provides fixed array functionality that won’t decay when passed into a function. 
    std::array is defined in the <array> header, inside the std namespace.

    Declaring a std::array variable is easy:
    */
    std::array<int, 3> myArray; // declare an integer array with length 3
    //the length of a std::array must be known at compile time.

    //std::array can be initialized using initializer lists or list initialization:
    std::array<int, 5> myArray_2 = { 9, 7, 5, 3, 1 };// initializer list
    std::array<int, 5> myArray_3 { 9, 7, 5, 3, 1 };// list initialization

    /*
    However, since C++17, it is allowed to omit the type and size. 
    They can only be omitted together, but not one or the other, and only if 
    the array is explicitly initialized.
    */
    std::array myArray_4 = { 9, 7, 5, 3, 1 };// The type is deduced to std::array<int, 5>
    std::array myArray_5 { 9.7, 7.31 };// The type is deduced to std::array<double, 2>

    //You can also assign values to the array using an initializer list:
    std::array<int, 5> myArray_6;
    myArray_6 = { 0, 1, 2, 3, 4 };// okay
    myArray_6 = { 9, 8, 7 };// okay, elements 3 and 4 are set to zero!
    // myArray_6 = { 0, 1, 2, 3, 4, 5 };// not allowed, too many elements in initializer list!

    /*
    std::array supports a second form of array element access 
    (the at() function) that does bounds checking:
    */
    std::array<double, 10> myArray_7 { 1, 4, 6, 4, 7, 8, 145 };
    myArray_7.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
    // myArray_7.at(11) = 7; // array element 11 is invalid, will throw an error

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Size and sorting" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}