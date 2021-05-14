#include <iostream>
#include <string>
#include <cstddef> //for NULL

void message(std::string s)
{
    std::cout << s << '\n';
}

int main()
{
    message("Hello World");

    ////////////////////////////////
    //Null values and null pointers
    ////////////////////////////////
    /*
    A null value is a special value that means the pointer is not pointing at anything. 
    A pointer holding a null value is called a null pointer.
    */
    float* ptr { 0 };// ptr is now a null pointer
    float* ptr2;// ptr2 is uninitialized
    ptr2 = 0;// ptr2 is now a null pointer

    /*
    Pointers convert to boolean false if they are null, and boolean true if they are non-null. 
    Therefore, we can use a conditional to test whether a pointer is null or not:
    */
    double* ptr_d { 0 };
    // pointers convert to boolean false if they are null, and boolean true if they are non-null
    if(ptr_d)
        std::cout << "ptr_d is pointing to a double value.\n";
    else
        std::cout << "ptr_d is a null pointer.\n";

    /*
    Best practice:

    Initialize your pointers to a null value if you’re not giving them another value.
    */

    ///////////////////////////////////
    //Indirection through null pointers
    ///////////////////////////////////
    /*
    Indirection through a pointer means “go to the address the pointer is pointing at 
    and access the value there”. A null pointer doesn’t have an address. So when you try 
    to access the value at that address, what should it do?
    */

    /////////////////
    //The NULL macro
    /////////////////
    double* ptr3 { NULL }; // ptr3 is a null pointer
    /*
    Best practice:

    Because NULL is a preprocessor macro with an implementation defined value, avoid using NULL.
    */

    ////////////////////////////////////////////////////
    //The perils of using 0 (or NULL) for null pointers
    ////////////////////////////////////////////////////
    /*
    In the likely case where NULL is defined as value 0, print(NULL) will call print(int), 
    not print(int*) like you might expect for a null pointer literal.
    */

    ///////////////////
    //nullptr in C++11
    ///////////////////
    /*
    To address the above issues, C++11 introduces a new keyword called nullptr. 
    nullptr is a keyword, much like the boolean keywords true and false are.
    */
    int* ptr4 { nullptr }; // note: ptr is still an integer pointer, just set to a null value

    /*
    Best practice

    Use nullptr to initialize your pointers to a null value.
    */

    /////////////////
    //std::nullptr_t
    /////////////////
    /*
    C++11 also introduces a new type called std::nullptr_t (in header <cstddef>). 
    std::nullptr_t can only hold one value: nullptr! While this may seem kind of silly, 
    it’s useful in one situation. If we want to write a function that accepts only a nullptr 
    argument, what type do we make the parameter? The answer is std::nullptr_t.
    */


    return 0;
}