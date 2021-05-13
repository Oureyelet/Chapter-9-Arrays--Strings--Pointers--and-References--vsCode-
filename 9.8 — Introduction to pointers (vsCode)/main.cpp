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
    int value{ 5 };
    std::cout << &value << '\n';// prints address of value
    std::cout << value << '\n';// prints contents of value

    int *ptr_2{ &value };// ptr_2 points to value
    std::cout << ptr_2 << '\n';// prints address held in ptr, which is &value
    std::cout << *ptr_2 << '\n';// Indirection through ptr (get the value that ptr is pointing to)

    //Once assigned, a pointer value can be reassigned to another value:
    int value_1{ 3 };
    int value_2{ 7 };

    int *ptr_3{};

    ptr_3 = &value_1; // ptr_3 points to value_1
    std::cout << *ptr_3 << '\n';//print 3

    ptr_3 = &value_2; // ptr_3 points to value_2
    std::cout << *ptr_3 << '\n';//print 7

    ////////////////////////////////////////////////////////
    // A warning about indirection through invalid pointers
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //                  The size of pointers
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //                  What good are pointers?
    ////////////////////////////////////////////////////////
    /*
    1) Arrays are implemented using pointers. Pointers can be used to iterate through an array 
    (as an alternative to array indices)
    
    2) They are the only way you can dynamically allocate memory in C++. 
    This is by far the most common use case for pointers.
    
    3) They can be used to pass a function as a parameter to another function.
    
    4) They can be used to achieve polymorphism when dealing with inheritance.
    
    5) They can be used to have one struct/class point at another struct/class, to form a chain. 
    This is useful in some more advanced data structures, such as linked lists and trees.
    */

    ////////////////////////////////////////////////////////
    //                  Quiz time
    ////////////////////////////////////////////////////////
    /*
    Question #1

    What values does this program print? Assume a short is 2 bytes, and a 32-bit machine.
    */
    std::cout << "//////////////" << '\n';
    std::cout << "Question 1 !" << '\n';
    std::cout << "//////////////" << '\n';

    short value_7{ 7 }; // &value = 0012FF60
    short otherValue{ 3 }; // &otherValue = 0012FF54
 
    short* ptr_7{ &value_7 }; // 0012FF60
 
    std::cout << &value_7 << '\n'; //print 0012FF60
    std::cout << value_7 << '\n';//print 7
    std::cout << ptr_7 << '\n';//print 0012FF60
    std::cout << *ptr_7 << '\n';//print 7
    std::cout << '\n';
 
    *ptr_7 = 9;
    //short* ptr_7{ 9 };
 
    std::cout << &value_7 << '\n'; //print 0012FF60
    std::cout << value_7 << '\n';//print 9 
    std::cout << ptr_7 << '\n';//print 0012FF60
    std::cout << *ptr_7  << '\n';//print 9
    std::cout << '\n';
 
    ptr_7 = &otherValue;
 
    std::cout << &otherValue << '\n';//print 0012FF54
    std::cout << otherValue << '\n';//print 3
    std::cout << ptr_7 << '\n';//print 0012FF54
    std::cout << *ptr_7 << '\n';//print 3
    std::cout << '\n';
 
    std::cout << sizeof(ptr_7) << '\n';
    std::cout << sizeof(*ptr_7) << '\n';

    /*
    Question #2

    What’s wrong with this snippet of code?
    */
    std::cout << "//////////////" << '\n';
    std::cout << "Question 2 !" << '\n';
    std::cout << "//////////////" << '\n';

    int value_12{ 45 };
    int* ptr_23{ &value_12 }; // print xxxxFFFF000
    *ptr_23 = 2; // assign address of value to ptr

    //anwser is *ptr should be assing with value not with adress.
    //or ptr = &value;





    



    return 0;
}