#include <iostream>
#include <array> // for std::array
#include <cstddef> //for size_t
#include <iterator> //for std::begin / std::end

int main()
{
    std::cout << "yo yo yo !" << '\n'; 

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Iterating through an array (or other structure) of data is quite a common thing to do in programming. 
    And so far, we’ve covered many different ways to do so: with loops and an index 
    (for-loops and while loops), with pointers and pointer arithmetic, and with range-based for-loops:
    */

    // The type is automatically deduced to std::array<int, 7> (Requires C++17).
    // Use the type std::array<int, 7> if your compiler doesn't support C++17.
    std::array<int, 7> data { 0, 1, 2, 3, 4, 5, 6 };
    std::size_t lenght { std::size(data) };

     // while-loop with explicit index
      std::size_t index { 0 };
      while(index != lenght)
      {
          std::cout << data[index] << ' ';
          ++index;
      }
      std::cout << std::endl;

     // for-loop with explicit index
     for(int count{ 0 }; count < lenght; ++count)
     {
        std::cout << data[count] << ' ';
     }
     std::cout << '\n';

     // for-loop with pointer (Note: ptr can't be const, because we increment it)
     for(auto ptr{ &data[0] }; ptr != (&data[0] + lenght); ++ptr)
     {
         std::cout << *ptr << ' ';
     }
     std::cout << '\n';

     // ranged-based for loop
     for(auto& dt : data)
     {
        std::cout << dt << ' ';
     }
     std::cout << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "iterators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    An iterator is an object designed to traverse through a container 
    (e.g. the values in an array, or the characters in a string), providing access to each 
    element along the way.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers as an iterator" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The simplest kind of iterator is a pointer, which (using pointer arithmetic) works for data 
    stored sequentially in memory. Let’s revisit a simple array traversal using a pointer and 
    pointer arithmetic:
    */

    std::array ourArray { 0, 1, 2, 3, 4, 5, 6 };

    auto begin { &ourArray[0] };
    // note that this points to one spot beyond the last element
    auto end { begin + std::size(ourArray) };

    // for-loop with pointer
    for(auto ptr{ begin }; ptr != end; ++ptr)// ++ to move to next element
    {
        std::cout << *ptr << ' ';// Indirection to get value of current element
    }
    std::cout << std::endl;

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Standard library iterators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Iterating is such a common operation that all standard library containers offer direct support 
    for iteration. Instead of calculating our own begin and end points, we can simply ask the 
    container for the begin and end points via functions conveniently named begin() and end():
    */
    std::array secondArray { 1, 2, 3 };

    // Ask our array for the begin and end points (via the begin and end member functions).
    auto begin_2{ secondArray.begin() };
    auto end_2{ secondArray.end() };

    for(auto p{ begin_2 }; p != end_2; ++p)// ++ to move to next element.
    {
        std:: cout << *p << ' ';// Indirection to get value of current element.
    }
    std::cout << '\n';

    //The iterator header also contains two generic functions (std::begin and std::end) that can be used:

    std::array thirdArray { 1, 2, 3 };

    // Use std::begin and std::end to get the begin and end points.
    auto begin_3{ std::begin(thirdArray) };
    auto end_3{ std::end(thirdArray) };

    for(auto p{ begin_3 }; p != end_3; ++p)// ++ to move to next element.
    {
        std:: cout << *p << ' ';// Indirection to get value of current element.
    }
    std::cout << '\n';

    /*
    Don’t worry about the types of the iterators for now, we’ll re-visit iterators in a later chapter. 
    The important thing is that the iterator takes care of the details of iterating through the container. 
    All we need are four things: the begin point, the end point, operator++ to move 
    the iterator to the next element (or the end), and operator* to get the value of the current element.
    */




    return 0;
}