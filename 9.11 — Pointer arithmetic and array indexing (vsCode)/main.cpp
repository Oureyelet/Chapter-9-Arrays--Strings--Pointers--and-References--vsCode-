#include <iostream>
#include <iterator> // for std::size, std::begin and std::end
#include <algorithm> 

bool isVowel(char);
int* find(int*,int*,int);


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

    //////////////
    //Quiz Time !
    //////////////
    /*
    Question #1

    Why does the following code work?

    #include <iostream>
 
    int main()
    {
        int arr[]{ 1, 2, 3 };
 
        std::cout << 2[arr] << '\n';
 
        return 0;
    }

    answser:

    The subscript operator ([]) is identical to an addition 
    and an indirection, the operands can be swapped.

    arr[2]
    // same as
    *(arr + 2)
    // same as
    *(2 + arr)
    // same as
    2[arr]
    */
    int array77[]{ 1, 2, 3, 4, 5, 6 };
    std::cout << array77[2] << '\n';
    std::cout << *(array77 + 2) << '\n';
    std::cout << *(2 + array77) << '\n';
    std::cout << 2[array77] << '\n';

    /*
    Question #2

    Write a function named find that takes a pointer to the beginning and 
    a pointer to the end (1 element past the last) of an array, as well as a value. 
    The function should search for the given value and return a pointer to 
    the first element with that value, or the end pointer if no element was found. 
    The following program should run:
    */
    int arrayMy[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ find(std::begin(arrayMy), std::end(arrayMy), 16) };

    // If an element with value 20 was found, print it.
    if(found != std::end(arrayMy))
    {
        std::cout << *found << '\n';
    }


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
    

int* find(int* begin,int* end, int value)
{
    for(int* count{ begin }; count != end; ++count)
    {
        if(*count == value)
        {
            return count;
        }
    }
    return end;
}