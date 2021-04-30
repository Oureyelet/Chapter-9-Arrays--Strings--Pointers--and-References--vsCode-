#include <iostream>
#include <string>
#include <iterator> // for std::size

    /*------------------------------
        Passing arrays to functions
    -------------------------------*/
    void passValue(int value)// value is a copy of the argument
    {
        value = 99;// so changing it here won't change the value of the argument
    }

    void passArray(int prime[5])// prime is the actual array
    {
        prime[0] = 11;// so changing it here will change the original argument!
        prime[1] = 7;
        prime[2] = 5;
        prime[3] = 3;
        prime[4] = 2;
    }

int main()
{
    std::cout << "hello world" << '\n';

    /*-------------------------
    Initializing fixed arrays
    --------------------------*/
    int prime[5]{2, 3, 5, 7, 11};// use initializer list to initialize the fixed array
    /*
    if there are less initializers in the list than the array can hold, the remaining 
    elements are initialized to 0 (or whatever value 0 converts to for a non-integral 
    fundamental type -- e.g. 0.0 for double). This is called 'zero initialization'.
    */
    //The following example shows this in action:
    int turtle[5]{2, 3, 5};// only initialize first 3 elements
    std::cout << turtle[0] << '\n';
    std::cout << turtle[1] << '\n';
    std::cout << turtle[2] << '\n';
    std::cout << turtle[3] << '\n';
    std::cout << turtle[4] << '\n';

    //Consequently, to initialize all the elements of an array to 0, you can do this:

    // Initialize all elements to 0
    int Elephantt[5]{ };

    // Initialize all elements to 0.0
    double Monkeyy[5]{ };

    // Initialize all elements to an empty string
    std::string giraffee[5]{ };

    /*-------------------------
        Omitted length
    --------------------------*/
    /*
    If you are initializing a fixed array of elements using an initializer list, 
    the compiler can figure out the length of the array for you, and you can omit 
    explicitly declaring the length of the array.
    */

    //The following two lines are equivalent:
    int fish[5]{2, 3, 5, 7, 11};// explicitly define the length of the array

    int fish2[]{2, 3, 5, 7, 11};// let the initializer list set length of the array

    /*-------------------------
        Arrays and enums
    --------------------------*/
    enum Students_Names
    {
        ania, // 1
        mateusz,// 2
        tobiasz,// 3
        klara,// 4
        max_students // 5
    };

    int testScores[max_students]{}; // allocate 5 integers
    testScores[ania] = 76;

    /*---------------------------
        Arrays and enums classes
    ----------------------------*/
    /*
    Enum classes don’t have an implicit conversion to integer, so if you try the following:
    (This can be addressed by using a static_cast to convert the enumerator to an integer)
    */
    enum class Students_Names_2
    {
        ania2, // 1
        mateusz2,// 2
        tobiasz2,// 3
        klara2,// 4
        max_students2 // 5
    };

    int testScores2[static_cast<int>(Students_Names_2::max_students2)]{};// allocate 6 integers
    testScores2[static_cast<int>(Students_Names_2::ania2)] = 76;

    /*------------------------------
        Passing arrays to functions
    -------------------------------*/
    int value{ 1 };
    std::cout << "before passValue: " << value << '\n';
    passValue(value);
    std::cout << "after passValue: " << value << '\n';

    int prime3[5]{2, 3, 5, 7, 11};
    std::cout << "before passArray: " << prime3[0] << ' ' << prime3[1] << ' ' << prime3[2] << ' ' <<
    prime3[3] << ' ' << prime3[4] << '\n';
    passArray(prime3); 
    std::cout << "after passArray: " << prime3[0] << ' ' << prime3[1] << ' ' << prime3[2] << ' ' <<
    prime3[3] << ' ' << prime3[4] << '\n';

    /*
    Why this happens is related to the way arrays are implemented in C++, a topic we’ll 
    revisit once we’ve covered pointers. For now, you can consider this as a quirk of the language.
    */

    /*--------------------------------------
       Indexing an array out of range
    --------------------------------------*/
    int array77[5]{};// hold the first 5 array77 numbers
    array77[5] = 777;

    /*
    C++ does not do any checking to make sure that your indices are valid for the length of your array. 
    So in the above example, the value of 13 will be inserted into memory where the 6th element would 
    have been had it existed. When this happens, you will get undefined behavior -- For example, 
    this could overwrite the value of another variable, or cause your program to crash.
    */

    /*-------------
       Quiz time !
    --------------*/

    /*
    1)

    Declare an array to hold the high temperature (to the nearest tenth of a degree) 
    for each day of a year (assume 365 days in a year). Initialize the array with a value
     of 0.0 for each day.
    */

    double high_temp[365]{};

    /*
    2)

    Set up an enum with the names of the following animals: chicken, dog, cat, elephant, 
    duck, and snake. Put the enum in a namespace. Define an array with an element for each of 
    these animals, and use an initializer list to initialize each element to hold the number 
    of legs that animal has.

    Write a main function that prints the number of legs an elephant has, using the enumerator.
    */

    return 0;
}

