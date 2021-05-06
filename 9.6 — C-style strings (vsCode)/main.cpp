#include <iostream>
#include <iterator>
#include <limits> // for for std::numeric_limits
#include <cstring> // for strcpy()

int main()
{
    /*-------------
    C-style strings
    -------------*/
    /*
    A C-style string is simply an array of characters that uses a null terminator. 
    A null terminator is a special character (‘\0’, ascii code 0) used to indicate 
    the end of the string. More generically, A C-style string is called a null-terminated string.

    To define a C-style string, simply declare a char array and initialize it with a string literal:
    */
    char myString[]{ "chrystus" };
    /*
    Although “string” only has 6 letters, C++ automatically adds a null terminator 
    to the end of the string for us (we don’t need to include it ourselves). 
    Consequently, myString is actually an array of length 7!
    */
    constexpr int lenght{ (sizeof(myString) / sizeof(myString[0])) - 1 };

    std::cout << myString << " has " << lenght << " characters.\n";

    for(int count{ 0 }; count < lenght; ++count)
    {
        std::cout << static_cast<int>(myString[count]) << ' ';
    }
    std::cout << '\n';

    /*
    Since C-style strings are arrays, you can use the [] operator to 
    change individual characters in the string:
    */
    myString[0] = 'C';
    std::cout << myString << '\n';

    /*--------------------------
    C-style strings and std::cin
    --------------------------*/
    /*
    There are many cases where we don’t know in advance how long our string is going to be. 
    For example, consider the problem of writing a program where we need to ask the user to 
    enter their name. How long is their name? We don’t know until they enter it!

    In this case, we can declare an array larger than we need:
    */
    char name[500];// declare array large enough to hold 500 characters
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Your name " << " is " << name << '\n';

    //The recommended way of reading C-style strings using std::cin is as follows:

    char surname[255];// declare array large enough to hold 255 characters
    int lenghtSurname{ (sizeof(surname) / sizeof(surname[0])) - 1 };
    std::cout << "Enter your surname: ";
    std::cin.getline(surname, lenghtSurname);
    std::cout << "Your surname is: " << surname << '\n';
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear(); // put us back in 'normal' operation mode
    /*
    This call to cin.getline() will read up to 254 characters into name 
    (leaving room for the null terminator!). Any excess characters will be discarded. 
    In this way, we guarantee that we will not overflow the array!
    */

    /*--------------------------
    Manipulating C-style strings
    --------------------------*/
    char day[]{ "Thursday" };
    char tomorrow[50];
    std::strcpy(day, tomorrow);
    std::cout << tomorrow << '\n';

    


    return 0;
}