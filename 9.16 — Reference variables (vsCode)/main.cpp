#include <iostream>
#include <string>

using namespace std;

void message(string);

int main()
{
    message("Hello Everyone!");

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References to non-const values" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    return 0;
}

void message(std::string s)
{
    std::cout << s << '\n';
}