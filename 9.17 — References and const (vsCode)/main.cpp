#include <iostream>

int someFCN(double x)
{
    const double& ref{ x + 3 };// normally the result of 2+3 has expression scope and is destroyed at the end of this statement
    // but because the result is now bound to a reference to a const value...

    std::cout << ref << '\n';// we can use it here

    return 0;
}// and the lifetime of the r-value is extended to here, when the const reference dies

// ref is a const reference to the argument passed in, not a copy
void changeN(const int& ref)
{
   // ref = 7; // not allowed, ref is const
}

void printIT(const int& x)
{
    std::cout << x << '\n';
}

int main()
{
    std::cout << "Hello World" << '\n';

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Reference to const value" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////

    const int value { 5 };
    const int& ref { value }; // ref is a reference to const value

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing references to const values" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    
    int x{ 7 };
    const int& ref_2{ x };// okay, x is a non-const l-value

    const int x_2{ 7 };
    const int& ref_3{ x_2 };// okay, y is a const l-value

    const int& ref_4{ 7 };// okay, 6 is an r-value

    /*
    Much like a pointer to a const value, a reference to a const value can reference 
    a non-const variable. When accessed through a reference to a const value, 
    the value is considered const even if the original variable is not:
    */
    int value_2{ 7 };
    const int& ref_5{ value_2 };// create const reference to variable value

    value_2 = 8;// okay, value is non-const
    // ref_5 = 5; // illegal -- ref is const

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "References to r-values extend the lifetime of the referenced value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    std::cout << 2 + 3 << '\n';// 2 + 3 evaluates to r-value 5, which is destroyed at the end of this statement

    someFCN(5.55); //look up for this function.

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const references as function parameters" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    changeN(5); //look up for this function.

    /*
    References to const values are particularly useful as function parameters because of their versatility. 
    A const reference parameter allows you to pass in a non-const l-value argument, 
    a const l-value argument, a literal, or the result of an expression:
    */
    int x_3{ 7 };
    printIT( x_3 );// non-const l-value

    const int x_4{ 8 };
    printIT( x_4 );// const l-value


    printIT( 3 );// literal r-value

    printIT( 2 + x_4 );// expression r-value

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    To avoid making unnecessary, potentially expensive copies, variables that are not pointers 
    or fundamental data types (int, double, etc…) should be generally passed by (const) reference. 
    Fundamental data types should be passed by value, unless the function needs to change them. 
    There are a few exceptions to this rule, namely types that are so small that it’s faster 
    for the CPU to copy them than having to perform an extra indirection for a reference.
    */

    /*
    A reminder:

    References act like pointers. The compiler adds the indirection, which we’d do 
    manually on a pointer using an asterisk, for us.

    One of those fast types is std::string_view. You’ll learn about more exceptions later. 
    If you’re uncertain if a non-fundamental type is fast to pass by value, pass it by const reference.
    */

    /*
    Best practice:

    Pass non-pointer, non-fundamental data type variables (such as structs) by (const) reference, 
    unless you know that passing it by value is faster.
    */




    return 0;
}