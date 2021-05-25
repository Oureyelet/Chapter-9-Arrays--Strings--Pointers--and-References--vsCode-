#include <iostream>

int main()
{
    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Pointing to const variables" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    /*const*/ int value{ 7 };
    int* ptr{ &value };
    *ptr = 8;
    std::cout << *ptr << '\n';
    std::cout << value << '\n';

    //The above snippet won’t compile -- we can’t set a non-const pointer to a const variable.

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Pointer to const value" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //Thus, the following is okay:
    int value_next{ 8 };
    const int* ptr_next{ &value_next };
    value_next = 7;

    std::cout << *ptr_next << '\n';
    std::cout << value_next << '\n';

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Const pointers" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    //A const pointer is a pointer whose value can not be changed after initialization

    int value_another{ 12 };
    int* const ptr_another{ &value_another };

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Const pointer to a const value" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    
    int valuee{ 77 };
    const int* const ptrr{ &valuee };

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "Recapping" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //To summarize, you only need to remember 4 rules, and they are pretty logical:
    /*
    -A non-const pointer can be redirected to point to other addresses.
    -A const pointer always points to the same address, and this address can not be changed. 

    -A pointer to a non-const value can change the value it is pointing to. 
    These can not point to a const value.
    -A pointer to a const value treats the value as const (even if it is not), and 
    thus can not change the value it is pointing to. 
    */
    /*
    int value{ 5 };
    const int* ptr1{ &value }; // ptr1 points to a "const int", so this is a pointer to a const value.
    int* const ptr2{ &value }; // ptr2 points to an "int", so this is a const pointer to a non-const value.
    const int* const ptr3{ &value }; // ptr3 points to a "const int", so this is a const pointer to a const value.
    */

    

    return 0;
}