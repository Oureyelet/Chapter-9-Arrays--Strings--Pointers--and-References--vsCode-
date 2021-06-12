#include <iostream>
#include <array> // for std::array
#include <cstddef> //for size_t

int main()
{
    std::cout << "yo yo yo !" << '\n'; 

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "iterating" << '\n';
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



    return 0;
}