#include <iostream>
#include <array> //for std::array
#include <algorithm>// for std::sort
#include <cstddef> // for template ? 

void printLenght(const std::array<double, 5> &myArray)
{
    std::cout << "lenght: " << myArray.size() << '\n';
}

void printArray(const std::array<double, 5>& myArray)
{
    for(auto& array : myArray)
    {
        std::cout << array << ' ';
    }
    std::cout << std::endl;
}

// printArray is a template function
template <class T, std::size_t size>// parameterize the element type and size

void printArray_template_function(const std::array<T, size>& myArray)
{
    for(auto& array : myArray)
    {
        std::cout << array << ' ';
    }
    std::cout << std::endl;
}

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

struct Array
{
    House value[3]{};
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An introduction to std::array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::array provides fixed array functionality that won’t decay when passed into a function. 
    std::array is defined in the <array> header, inside the std namespace.

    Declaring a std::array variable is easy:
    */
    std::array<int, 3> myArray; // declare an integer array with length 3
    //the length of a std::array must be known at compile time.

    //std::array can be initialized using initializer lists or list initialization:
    std::array<int, 5> myArray_2 = { 9, 7, 5, 3, 1 };// initializer list
    std::array<int, 5> myArray_3 { 9, 7, 5, 3, 1 };// list initialization

    /*
    However, since C++17, it is allowed to omit the type and size. 
    They can only be omitted together, but not one or the other, and only if 
    the array is explicitly initialized.
    */
    std::array myArray_4 = { 9, 7, 5, 3, 1 };// The type is deduced to std::array<int, 5>
    std::array myArray_5 { 9.7, 7.31 };// The type is deduced to std::array<double, 2>

    //You can also assign values to the array using an initializer list:
    std::array<int, 5> myArray_6;
    myArray_6 = { 0, 1, 2, 3, 4 };// okay
    myArray_6 = { 9, 8, 7 };// okay, elements 3 and 4 are set to zero!
    // myArray_6 = { 0, 1, 2, 3, 4, 5 };// not allowed, too many elements in initializer list!

    /*
    std::array supports a second form of array element access 
    (the at() function) that does bounds checking:
    */
    std::array<double, 10> myArray_7 { 1, 4, 6, 4, 7, 8, 145 };
    myArray_7.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
    // myArray_7.at(11) = 7; // array element 11 is invalid, will throw an error

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Size and sorting" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    
    //The size() function can be used to retrieve the length of the std::array:
    std::array<double, 5> myArray_8 { 9.0, 7.2, 5.4, 3.6, 1.8 };
    std::cout << "lenght: " << myArray_8.size() << '\n';

    /*
    Because std::array doesn’t decay to a pointer when passed to a function, 
    the size() function will work even if you call it from within a function:
    */
    printLenght(myArray_8);

    /*
    Best practice

    Always pass std::array by reference or const reference !
    */

    //Because the length is always known, range-based for-loops (also call: For-each loop) work with std::array:
    std::array<int, 5> myArray_9 { 3, 6, 8, 4, 77 };

    for(int& myArray : myArray_9)
    {
        std::cout << myArray << ' ';
    }
    std::cout << std::endl;

    //You can sort std::array using std::sort, which lives in the <algorithm> header:
    std::array<int, 5> myArray_10 { 7, 3, 1, 9, 5 };
 //   std::sort( myArray_10.begin(), myArray_10.end() );// sort the array forwards
    std::sort( myArray_10.rbegin(), myArray_10.rend() );// sort the array backwards

    for(auto& myArray : myArray_10)
    {
        std::cout << myArray << ' ';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing std::array of different lengths to a function" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    printArray(myArray_8);

    /*
    The downside is that this limits our function to only handling arrays of this specific type and length. 
    But what if we want to have our function handle arrays of different element types or lengths? 
    We’d have to create a copy of the function for each different element type and/or array length 
    we want to use. That’s a lot of duplication.

    Fortunately, we can have C++ do this for us, using a feature called templates. We haven’t covered 
    templates yet, but the basic idea is that we can create a template function that parameterizes part 
    or all of the type information, and then C++ will use that template to create “real” functions 
    (with actual types) as needed.
    */
    std::array<double, 5> myArray_11 { 9.0, 7.2, 5.44, 3.6, 1.8 };
    std::array<double, 7> myArray_12 { 9.0, 7.2, 5.44, 3.6, 1.8, 56.4, 67.8 };
    std::array<double, 4> myArray_13 { 7, 44, 6, 1 };
    printArray_template_function(myArray_11);
    printArray_template_function(myArray_12);
    printArray_template_function(myArray_13);

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Manually indexing std::array via size_type" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    
    //Pop quiz: What’s wrong with the following code?:
    std::array<int, 5> myArray_14 { 7, 3, 1, 9, 5 };
 
    // Iterate through the array and print the value of the elements
    for (int i{ 0 }; i < myArray_14.size(); ++i)
    {
        std::cout << myArray_14[i] << ' ';
    }
    std::cout << '\n';

    //shout be:
    /*
    // std::array<int, 5>::size_type is the return type of size()!

    for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
    */

    //about more manually indexing std::array go see: https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray/

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "std::Array of struct" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////

    std::array<House, 3> houses{};

    houses[0] = { 13, 4, 30 };
    houses[1] = { 14, 3, 10 };
    houses[2] = { 15, 3, 40 };

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number 
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }

    //or:

    std::array<House, 3> houses_2 { 
        { { 13, 4, 30 }, { 14, 3, 10 }, { 15, 3, 40 } }
        };
    for (const auto& house : houses_2)
    {
        std::cout << "House number " << house.number 
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::array is a great replacement for built-in fixed arrays. It's efficient, in that it doesn’t 
    use any more memory than built-in fixed arrays. The only real downside of a std::array over a 
    built-in fixed array is a slightly more awkward syntax, that you have to explicitly specify the 
    array length (the compiler won’t calculate it for you from the initializer, unless you also 
    omit the type, which isn't always possible), and the signed/unsigned issues with size and indexing. 
    But those are comparatively minor quibbles — we recommend using std::array over built-in 
    fixed arrays for any non-trivial array use.
    */


    return 0;
}