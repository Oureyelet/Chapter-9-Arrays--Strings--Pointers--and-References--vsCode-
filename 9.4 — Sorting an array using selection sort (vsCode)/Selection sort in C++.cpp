#include <cstddef>
#include <iostream>
#include <iterator>
#include <utility>
 
int main()
{
  int array[]{ 30, 50, 20, 10, 40, 2 };
  constexpr std::size_t length{ sizeof(array) / sizeof(array[0]) };
 
  // Step through each element of the array
  // (except the last one, which will already be sorted by the time we get there)
  for (std::size_t startIndex{ 0 }; startIndex < length - 1; ++startIndex)
  {
    // smallestIndex is the index of the smallest element we’ve encountered this iteration
    // Start by assuming the smallest element is the first element of this iteration
    std::size_t smallestIndex{ startIndex };
 
    // Then look for a smaller element in the rest of the array
    for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
    {
      // If we've found an element that is smaller than our previously found smallest
      if (array[currentIndex] < array[smallestIndex])
      {
        // then keep track of it
        smallestIndex = currentIndex;
      }
    }
 
    // smallestIndex is now the smallest element in the remaining array
                // swap our start element with our smallest element (this sorts it into the correct place)
    std::swap(array[startIndex], array[smallestIndex]);
  }
 
  // Now that the whole array is sorted, print our sorted array as proof it works
  for (std::size_t index{ 0 }; index < length; ++index)
    std::cout << array[index] << ' ';
 
  std::cout << '\n';

  /*
  Sorting names works using the same algorithm. Just change the array type from 
  int to std::string, and initialize with the appropriate values.
  */
 
  return 0;
}