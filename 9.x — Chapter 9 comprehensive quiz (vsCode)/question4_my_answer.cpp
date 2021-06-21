#include <iostream>

void myString()
{
    char c_style[] { "Hello, world!" };

    char* p;
    p = c_style;

    for(p ; *p != '\0'; ++p)
    {
        std::cout << *p;
    }
    std::cout << '\n';
}

int main()
{
    myString();

    return 0;
}


/*
Question #4

Write a function to print a C-style string character by character. Use a pointer to step through 
each character of the string and print that character. Stop when you hit the null terminator. 
Write a main function that tests the function with the string literal “Hello, world!”.
*/