#include <iostream>
#include <iterator>
#include <cstring> // for strcpy() and strlen()

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
    Although “chrystus” only has 8 letters, C++ automatically adds a null terminator 
    to the end of the string for us (we don’t need to include it ourselves). 
    Consequently, myString is actually an array of length 9!
    */
    constexpr int lenght{ sizeof(myString) / sizeof(myString[0]) };//(8 letters + null terminator)

    std::cout << myString << " has " << lenght << " characters.\n"; //(8 letters + null terminator)

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
    char name[100];// declare array large enough to hold 500 characters
    std::cout << "Enter your name: ";
    std::cin.getline(name, 100, '\n'); 
    std::cout << "Your name " << " is " << name << '\n';

    //The recommended way of reading C-style strings using std::cin is as follows:

    char surname[55];// declare array large enough to hold 255 characters
    std::cout << "Enter your surname: ";
    std::cin.getline(surname, 55, '\n');
    std::cout << "Your surname is: " << surname << '\n';
   
    /*
    This call to cin.getline() will read up to 254 characters into name 
    (leaving room for the null terminator!). Any excess characters will be discarded. 
    In this way, we guarantee that we will not overflow the array!
    */

    /*------------------
    Copy C-style strings
    ------------------*/
    char day[]{ "Friday" };
    char tomorrow[50];
    std::strcpy(tomorrow, day);
    std::cout << tomorrow << '\n';

    /*------
    strlen() 
    ------*/

    char myName[20]{ "Anna" };// only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << myName << '\n';
    std::cout << myName << " has " << std::strlen(myName) << " letters.\n";
    std::cout << myName << " has " << sizeof(myName) / sizeof(myName[0]) << " characters in the array.\n";

    /*------------------------------------------------------------------
    Here’s an example program using some of the concepts in this lesson:
    ------------------------------------------------------------------*/
    // Ask the user to enter a string
    char buffer[255];
    std::cout << "Enter a string: ";
    std::cin.getline(buffer, sizeof(buffer)/sizeof(buffer[0]));

    int spaceFound{ 0 };
    int bufferLenght{ static_cast<int>(std::strlen(buffer)) };

    // Loop through all of the characters the user entered
    for(int count{ 0 }; count < bufferLenght; ++count)
    {
        // If the current character is a space, count it
        if(buffer[count] == ' ')
        {
            ++spaceFound;
        }
    }

    std::cout << "You typed " << spaceFound << " spaces!\n";

    


    return 0;
}