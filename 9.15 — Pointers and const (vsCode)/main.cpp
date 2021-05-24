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
    


    

    return 0;
}