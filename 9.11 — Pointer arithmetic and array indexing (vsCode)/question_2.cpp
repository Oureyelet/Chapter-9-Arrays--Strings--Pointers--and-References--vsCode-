/*
Question #2

Write a function named find that takes a pointer to the beginning and a pointer 
to the end (1 element past the last) of an array, as well as a value. 
The function should search for the given value and return a pointer to the first element 
with that value, or the end pointer if no element was found. The following program should run:
*/

#include <iostream>
#include <iterator>
 
int* find(int*,int*,int);
 
int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
    std::cout << "Which value you want to search in our array ? :";
    int seearch{};
    std::cin >> seearch;
    // Search for the first element with value 20.
    int* found{ find(std::begin(arr), std::end(arr), seearch ) };
 
    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << "Yes " <<*found << " is here :)" <<'\n';
    }
 
    return 0;
}

int* find(int* begin, int* end,int value)
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