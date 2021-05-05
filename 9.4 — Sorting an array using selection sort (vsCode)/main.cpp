#include <iostream>
#include <utility>
#include <algorithm>

int main()
{
    std::cout << "ello !\n";

    /*----------------
    A case for sorting
    ----------------*/

    /*---------------
    How sorting works
    ---------------*/
    /*
    Sorting is generally performed by repeatedly comparing pairs of array elements, and swapping 
    them if they meet some predefined criteria. The order in which these elements are compared 
    differs depending on which sorting algorithm is used. The criteria depends on how the list 
    will be sorted (e.g. in ascending or descending order).

    To swap two elements, we can use the std::swap() function from the C++ standard library, which 
    is defined in the utility header.
    */

    int x{ 2 };
    int y{ 4 };
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';

    std::swap(x, y); // swap the values of x and y

    std::cout << "After swap: x = " << x << ", y = " << y << '\n';

    //Note that after the swap, the values of x and y have been interchanged!

    /*------------
    Selection sort
    ------------*/
/*
Here is an example of this algorithm working on 5 elements. Let’s start with a sample array:

{ 30, 50, 20, 10, 40 }

First, we find the smallest element, starting from index 0:

{ 30, 50, 20, 10, 40 }

We then swap this with the element at index 0:

{ 10, 50, 20, 30, 40 }

Now that the first element is sorted, we can ignore it. Now, we find the smallest element, starting from index 1:

{ 10, 50, 20, 30, 40 }

And swap it with the element in index 1:

{ 10, 20, 50, 30, 40 }

Now we can ignore the first two elements. Find the smallest element starting at index 2:

{ 10, 20, 50, 30, 40 }

And swap it with the element in index 2:

{ 10, 20, 30, 50, 40 }

Find the smallest element starting at index 3:

{ 10, 20, 30, 50, 40 }

And swap it with the element in index 3:

{ 10, 20, 30, 40, 50 }

Finally, find the smallest element starting at index 4:

{ 10, 20, 30, 40, 50 }

And swap it with the element in index 4 (which doesn’t do anything):

{ 10, 20, 30, 40, 50 }

Done!

{ 10, 20, 30, 40, 50 }

Note that the last comparison will always be with itself (which is redundant), 
so we can actually stop 1 element before the end of the array.
*/

    /*-------------------
    Selection sort in C++
    -------------------*/
    //Here’s how this algorithm is implemented in C++:
    //(go see Selection sort in C++.cpp )

    /*-------
    std::sort
    -------*/
    int array[]{ 30, 50, 20, 10, 40 };
    int numArray{ sizeof(array) / sizeof(array[0]) };

    std::sort(std::begin(array), std::end(array));

    for(std::size_t count { 0 }; count < numArray ; ++count)
    {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    /*
    By default, std::sort sorts in ascending order using operator< to compare pairs 
    of elements and swapping them if necessary (much like our selection sort example does above).
    */

    /*-------
    Quiz time
    -------*/
    /*
    Question #1

    Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }. 
    Show the array after each swap that takes place.
    */
    //anwser:
    /*
    { 30, 60, 20, 50, 40, 10 }
    ---------------------------
    { 10, 60, 20, 50, 40, 30 }
    { 10, 20, 60, 50, 40, 30 }
    { 10, 20, 30, 50, 40, 60 }
    { 10, 20, 30, 40, 50, 60 }
    { 10, 20, 30, 40, 50, 60 }
    */

    /*
    Question #2

    Rewrite the selection sort code above to sort in descending order 
    (largest numbers first). Although this may seem complex, it is actually surprisingly simple.
    */
    //anwser:
    int array1[]{ 30, 50, 20, 10, 40 };
    int numArray1{ sizeof(array1) / sizeof(array1[0]) };

    std::sort(std::begin(array1), std::end(array1));

    for(std::size_t count { 0 }; count < numArray1 ; ++count)
    {
        std::swap(array1[0], array1[4]);
        std::cout << array1[count] << ' ';
        std::swap(array1[1], array1[3]);
    }

    std::cout << '\n';
    



    
    return 0;
}