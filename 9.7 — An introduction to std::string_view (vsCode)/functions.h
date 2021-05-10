#include <iostream>
#include <cstring>
#include <iterator>


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

#endif // end FUNCTIONS_H