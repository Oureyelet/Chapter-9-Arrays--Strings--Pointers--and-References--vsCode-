#include <iostream>
#include <iterator> // for std::size, std::begin and std::end
#include <algorithm> 

bool isVowel(char);

int main()
{
    /////////////////////
    //Pointer arithmetic
    /////////////////////
    int value { 7 };
    int* ptr { &value };

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';

    /////////////////////////////////////////////
    //Arrays are laid out sequentially in memory
    /////////////////////////////////////////////
    int array[]{ 9, 7, 5, 3, 1 };

    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';

    ////////////////////////////////////////////////////////////
    //Pointer arithmetic, arrays, and the magic behind indexing
    ////////////////////////////////////////////////////////////

    std::cout << &array[1] << '\n';// print memory address of array element 1
    std::cout << array+1 << '\n';// print memory address of array pointer + 1 
    std::cout << array[1] << '\n';// prints 7
    std::cout << *(array+1) << '\n';// prints 7 (note the parenthesis required here)

    //////////////////////////////////////////////
    //Using a pointer to iterate through an array
    //////////////////////////////////////////////

    char name[]{ "Jezus" };
    int arrayLenght{ static_cast<int>(std::size(name)) };
    int numVowel{ 0 };

    for(char* count{ name }; count != (name + arrayLenght); ++count)
    {
        if(isVowel(*count))
        {
            ++numVowel;
        }
    }
    std::cout << name << " has " << numVowel << " vowels.\n";

    /*
    Because counting elements is common, the algorithms library offers 
    std::count_if, which counts elements that fulfill a condition. 
    We can replace the for-loop with a call to std::count_if.
    */

    char surname[]{ "Kacperski" };
    auto numVowels2{ std::count_if( std::begin(surname), std::end(surname), isVowel ) };

    std::cout << surname << " has " << numVowels2 << " vowels.\n";




    return 0;
}

    bool isVowel(char ch)
    {
        switch(ch)
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                return true;
            default:
                return false;
        }
    }