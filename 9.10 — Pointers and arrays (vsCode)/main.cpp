#include <iostream>

int main()
{
    //////////////
    //Array decay
    //////////////
    int array[5]{ 9, 7, 5, 3, 1 };// declare a fixed array of 5 integers

    std::cout << "Our arrays is: ";
    for(int count{ 0 }; count < std::size(array); ++count)
    {
        std::cout << array[count] << ' ';
    }
        std::cout << '\n';


    // print address of the array's first element
    std::cout << "Element 1 has address: " << &array[1] << '\n';

    int* ptr{ &array[1] };

    std::cout << "Pointer of 1 arrays is: " << *ptr << '\n';

    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    // Indirection through an array returns the first element (element 0) = print 9
    std::cout << "The array first value is: " << *array << '\n';

    char name[]{ "Jason" };// C-style string (also an array)
    // Indirection through an array returns the first element (element 0) = print J
    std::cout << *name << '\n'; 

    //We can also assign a pointer to point at the array:
    int* ptr2{ array };
    std::cout << *ptr2 << '\n';

    ///////////////////////////////////////////////
    //Differences between pointers and fixed arrays
    ///////////////////////////////////////////////
    



    return 0;
}