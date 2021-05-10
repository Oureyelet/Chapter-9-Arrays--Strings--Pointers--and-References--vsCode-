#include <iostream>
#include <cstring>
#include <iterator>
#include <string_view>
#include <string>


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void message()
{
    std::cout << "Hello World!" << '\n';
}

char speak()
{
    char word[]{ "Hello World Again :)" };
    std::cout << word << " has " << std::size(word) << " characters array.\n";//(20 letters + null terminator)
    std::cout << word << " has " << std::strlen(word) << " letters.\n";

    return 0;
}

std::string_view askForName()
{
    std::cout << "What's your name?\n";

    // Use a std::string, because std::cin needs to modify it.
    std::string anwser{};
    std::getline(std::cin, anwser);

    std::cout << "Hello " << anwser << '\n';

    return anwser;
}

void print(std::string s)
{
    std::cout << s << '\n';
}

#endif // end FUNCTIONS_H