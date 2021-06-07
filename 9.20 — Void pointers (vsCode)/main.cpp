#include <iostream>
#include <string_view>
#include <string>

void subject(std::string s)
{
    constexpr std::string_view unicode[] {
        "▀▄─", "▄▀─", "▀─▄", "▄─▀"
    };
 
    for (int y{}, p{}; y != 2; ++y, p = ((p + 1) % 4)) {
        for (int x{}; x != 10; ++x)
            std::cout << unicode[p];
        std::cout << '\n';
    }
    std::cout << s << '\n';
}

struct Something
{
    int n;
    float f;
};

enum class Type
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void *ptr, Type type)
{
    switch(type)
    {
        case Type::INT:
            std::cout << *static_cast<int*>(ptr) << '\n';// cast to int pointer and perform indirection
            break;

        case Type::FLOAT:
            std::cout << *static_cast<float*>(ptr) << '\n';// cast to float pointer and perform indirection
            break;

        case Type::CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n';// cast to char pointer (no indirection)
            // std::cout knows to treat char* as a C-style string
            // if we were to perform indirection through the result, then we'd just print the single char that ptr is pointing to
            break;
    }
}

int main()
{
    subject("Ha yaaa");

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Void pointer" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The void pointer, also known as the generic pointer, is a special type of pointer that 
    can be pointed at objects of any data type! A void pointer is declared like a normal pointer, 
    using the void keyword as the pointer’s type:
    */
    void *ptr; // ptr is a void pointer

    //A void pointer can point to objects of any data type:
    int nValue;
    float fValue;

    Something sValue;

    ptr = &nValue; // valid
    ptr = &fValue; // valid
    ptr = &sValue; // valid

    int n_1Value{ 5 };
    float f_1Value{ 7.5f };
    char arrValue[]{ "Mollie" };

    printValue(&n_1Value, Type::INT);
    printValue(&f_1Value, Type::FLOAT);
    printValue(arrValue, Type::CSTRING);

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Void pointer miscellany" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    //Void pointers can be set to a null value:
    void *ptr_2{ nullptr };// ptr is a void pointer that is currently a null pointer

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    //In general, it is a good idea to avoid using void pointers unless absolutely necessary :)


    

    return 0;
}