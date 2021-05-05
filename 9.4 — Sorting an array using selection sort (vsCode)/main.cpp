#include <iostream>
#include <utility>

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

    
    return 0;
}