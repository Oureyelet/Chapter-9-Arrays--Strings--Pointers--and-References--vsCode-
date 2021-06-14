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

bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return(a > b);
}

void(int *begin, int *end)
{
    for(auto startElement)
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







    return 0;
}