#include <iostream>
#include <algorithm> //for all algorithm library
#include <array> // for std::array
#include <string_view> // for string_view
#include <utility> //for std::swap 

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    /*
    std::string_view::find returns std::string_view::npos if it doesn't find
    the substring. Otherwise it returns the index where the substring occurs in str.
    */
   return (str.find("nut") != std::string_view::npos);
}

bool greater(int& a, int& b)
{
    // Order @a before @b if @a is greater than @b.
    return(a > b);
}

void sort(int *begin, int *end)
{
    for(auto startElement{ begin }; startElement != end; ++startElement)
    {
        auto smallestElement{ startElement };

        // std::next returns a pointer to the next element, just like (startElement + 1) would.
        for(auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
        {
            if(*currentElement < *smallestElement)
            {
                smallestElement = currentElement;
            }
        }
        std::swap(*startElement, *smallestElement);
    }
}

void doubleNumber(int &i)
{
    i *= 2; // same as i = i * 2
}

int main()
{
    std::cout << "Hello World" << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Algorithms library" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Inspectors -- Used to view (but not modify) data in a container. 
    Examples include searching and counting.
    
    Mutators -- Used to modify data in a container. Examples include sorting and shuffling.
    
    Facilitators -- Used to generate a result based on values of the data members. 
    Examples include objects that multiply values, or objects that determine what 
    order pairs of elements should be sorted in. 
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::find to find an element by value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::find searches for the first occurrence of a value in a container. 
    std::find takes 3 parameters: an iterator to the starting element in the sequence, 
    an iterator to the ending element in the sequence, and a value to search for. 
    It returns an iterator pointing to the element (if it is found) or the end of the container 
    (if the element is not found).
    */
    std::array arr { 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of

    // the iterator (since we don't care)
    auto found { std::find( arr.begin(), arr.end(), search ) };

    // Algorithms that don't find what they were looking for return the end iterator.

    // We can access it by using the end() member function.
    if(found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found = replace;
    }

    for(auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::find_if to find an element that matches some condition" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Sometimes we want to see if there is a value in a container that matches some condition 
    (e.g. a string that contains a specific substring) rather than an exact value. 
    In such cases, std::find_if is perfect. The std::find_if function works similarly to 
    std::find, but instead of passing in a value to search for, we pass in a callable object, 
    such as a function pointer (or a lambda, which we’ll cover later) that checks to see if 
    a match is found. std::find_if will call this function for every element until a matching element 
    is found (or no more elements remain in the container to check).

    Here’s an example where we use std::find_if to check if any elements contain the substring “nut”:
    */
    std::array<std::string_view, 5> arr_string { "apple", "banana", "walnut", "lemon", "peanut" };

    // Scan our array to see if any elements contain the "nut" substring
    auto found_2 { std::find_if( arr_string.begin(), arr_string.end(), containsNut ) };
    
    if( found_2 == arr_string.end() )
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found_2 << '\n';
    }

    
    std::cout << std::endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "///////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::count and std::count_if to count how many occurrences there are" << '\n';
    std::cout << "///////////////////////////////////////////////////////////////////////////" << '\n';
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::count and std::count_if search for all occurrences of an element or an element 
    fulfilling a condition.

    In the following example, we’ll count how many elements contain the substring “nut”:
    */

    auto nuts { std::count_if( arr_string.begin(), arr_string.end(), containsNut ) };

    std::cout << "Counted " << nuts << " nut(s)\n";


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::sort to custom sort" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    We previously used std::sort to sort an array in ascending order, but std::sort can do more than that. 
    There’s a version of std::sort that takes a function as its third parameter that allows us 
    to sort however we like. The function takes two parameters to compare, and returns true if the first 
    argument should be ordered before the second. By default, std::sort sorts the elements in ascending 
    order.

    Let’s use std::sort to sort an array in reverse order using a custom comparison function named greater:
    */
    std::array sort_Arr{ 13, 90, 99, 5, 40, 80 };

    // Pass greater to std::sort
    std::sort( sort_Arr.begin(), sort_Arr.end(), greater );

    for(auto& i : sort_Arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    /*
    Tip

    Because sorting in descending order is so common, C++ provides a custom type 
    (named std::greater) for that too (which is part of the functional header).
    https://en.cppreference.com/w/cpp/header/functional
    */
   
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::sort (For advanced readers)" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    int array_a[]{ 2, 1, 9, 4, 5 };

    sort(std::begin(array_a), std::end(array_a));

    for(auto& i : array_a)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::for_each to do something to all elements of a container" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::for_each takes a list as input and applies a custom function to every element. 
    This is useful when we want to perform the same operation to every element in a list.

    Here’s an example where we use std::for_each to double all the numbers in an array:
    */
    std::array array_7{ 1, 2, 3, 4 };

    std::for_each(array_7.begin(), array_7.end(), doubleNumber);

    for(auto& i : array_7)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    /*
    This often seems like the most unnecessary algorithm to new developers, because equivalent 
    code with a range-based for-loop is shorter and easier. But there are benefits to std::for_each. 
    Let’s compare std::for_each to a range-based for-loop.
    */
    std::for_each(array_7.begin(), array_7.end(), doubleNumber);

    for(auto& i : array_7)
    {
        doubleNumber(i);
        std::cout << i << ' ';
    }
    std::cout << '\n';


    /*
    Additionally, std::for_each can skip elements at the beginning or end of a container, 
    for example to skip the first element of arr, std::next can be used to advance begin to 
    the next element.
    */
    std::for_each( std::next(array_7.begin()), array_7.end(), doubleNumber );
    // Now arr is [1, 4, 6, 8]. The first element wasn't doubled.


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Order of execution" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////// 
    /*
    The following algorithms do guarantee sequential execution: 
    std::for_each, std::copy, std::copy_backward, std::move, and std::move_backward.
    */ 

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Ranges in C++20" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Having to explicitly pass arr.begin() and arr.end() to every algorithm is a bit annoying. 
    But fear not -- C++20 adds ranges, which allow us to simply pass arr. 
    This will make our code even shorter and more readable.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Best practice

    Favor using functions from the algorithms library over writing your own functionality 
    to do the same thing
    */



    return 0;
}