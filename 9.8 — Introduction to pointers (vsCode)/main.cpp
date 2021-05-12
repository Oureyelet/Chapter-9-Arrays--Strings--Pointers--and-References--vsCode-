#include <iostream>
#include "functions.h"
#include <typeinfo> // for typeid

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
    /*
    (also called dereference operator)
    */
    std::cout << *(&x) << '\n';
    /*
    print the value at the memory address of variable x (parenthesis not required, 
    but make it easier to read)
    */

    ///////////////////////////////////////
    //              Pointers
    ///////////////////////////////////////
    /*
    A pointer is a variable that holds a memory address as its value.
    */

    ///////////////////////////////////////
    //          Declaring a pointer
    ///////////////////////////////////////
    int *iPtr{};// a pointer to an integer value
    double *dPtr{};// a pointer to a double value

    int* iPtr2{};// also valid syntax
    double * dPtr2{};// also valid syntax (but don't do this, it looks like multiplication)

    /*
    When declaring multiple variables in one line, the asterisk has to appear
    once for every variable.
    */
    int *iPtr3{}, *dPtr3{};// declare two pointers to integer variables (not recommended)
    /*
    Syntactically, C++ will accept the asterisk next to the data type, 
    next to the variable name, or even in the middle.
    */
    /*
    Best practice:

    When declaring a pointer variable, put the asterisk next to the type to make 
    it easier to distinguish it from an indirection.
    */

    ///////////////////////////////////////
    //    Assigning a value to a pointer
    ///////////////////////////////////////
    /*
    To get the address of a variable, we use the address-of operator:
    */
    int v{ 5 };
    int* ptr4{ &v };// initialize ptr with address of variable v

    //So we say that ptr4 is “pointing to” v.

    std::cout << &v << '\n';// print the address of variable v
    std::cout << ptr4 << '\n';// print the address that ptr is holding

    //////////////////////////////////////////////
    //The address-of operator returns a pointer
    //////////////////////////////////////////////
    int z{ 5 };
    std::cout << typeid(&z).name() << '\n';
    //This pointer can then be printed or assigned as desired.

    //////////////////////////////////////////////
    //          Indirection through pointers
    //////////////////////////////////////////////
    









    return 0;
}