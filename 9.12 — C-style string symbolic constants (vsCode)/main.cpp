#include <string>
#include <iostream>

void message(std::string);
const char* ourNames();

int main()
{
    message( "Hello World" );

    char myName[]{ "Anna" };// fixed array
    std::cout << myName << '\n';

    const char* mySurname[]{ "Kacperska" };// pointer to symbolic constant
    std::cout << *mySurname << '\n';

    std::cout << ourNames() << '\n';

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "---->  std::cout and char pointers  <----" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    
    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hi Yaa" };
    const char* hisName{ "Alex" };

    std::cout << nArray << '\n'; // nArray will decay to type int*
    std::cout << cArray << '\n'; // cArray will decay to type char*
    std::cout << hisName << '\n';// name is already type char*

    //Consider the following case:
    char c{ 'Q' };
    std::cout << &c << '\n';

    return 0;
}

void message(std::string x)
{
    std::cout << x << '\n';
}

const char* ourNames()
{
    return "Anna i Mateusz";
}