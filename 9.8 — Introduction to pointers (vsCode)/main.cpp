#include <iostream>
#include "functions.h"

int main()
{
    print("Hello World");

    ///////////////////////////////////////
    //     The address-of operator (&)
    ///////////////////////////////////////
    int x{ 5 };
    std::cout << x << '\n';// print the value of variable x
    std::cout << &x << '\n';// print the memory address of variable x

    ///////////////////////////////////////
    //     The indirection operator (*)
    ///////////////////////////////////////
    

    return 0;
}