#include <iostream>

// function prototypes:
void printSize(int*); 
void changeArray(int*);

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
    /*
    will print sizeof(int) * array length
    and sizeof returns the number of bytes.
    */
    std::cout << sizeof(array) << '\n';


    std::cout << sizeof(ptr2) << '\n';// will print the size of a pointer

    ///////////////////////////////////////////////
    //Revisiting passing fixed arrays to functions
    ///////////////////////////////////////////////
    /*
    When passing an array as an argument to a function, a fixed array decays into a pointer, 
    and the pointer is passed to the function:
    */
    int array2[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array2) << '\n';// will print sizeof(int) * array length

    printSize(array2);// the array argument decays into a pointer here

    //////////////////////////////
    //An intro to pass by address
    //////////////////////////////
    int array3[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "(array3) Element 0 has value: " << array3[0] << '\n';

    changeArray(array3);


    std::cout << "(array3) Element 0 has value: " << array3[0] << '\n';

    ////////////////////////////////////////////
    //Arrays in structs and classes don’t decay
    ////////////////////////////////////////////
    
    
    return 0;
}

void printSize(int* array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n';// prints the size of a pointer, not the size of the array!
}

// parameter ptr contains a copy of the array's address
void changeArray(int* ptr)
{
    *ptr = 5;// so changing an array element changes the _actual_ array
}
