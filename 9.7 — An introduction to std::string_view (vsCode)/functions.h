#include <iostream>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void message()
{
    std::cout << "Hello World!" << '\n';
}

char speak()
{
    char word[]{ "Hello World Again :)" };
    std::cout << word << " has " << sizeof(word) / sizeof(word[0]) << " characters array\n";

    return 0;
}

#endif // end FUNCTIONS_H