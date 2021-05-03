#include <iostream>

int main()
{
    std::cout << "Hello World" << '\n';

    /*
    Consider the case where you want to record the test scores for 30 students in a class. 
    Without arrays, you would have to allocate 30 almost-identical variables!
    */
    /*
    // allocate 30 integer variables (each with a different name)
    int testScoreStudent1{};
    int testScoreStudent2{};
    int testScoreStudent3{};
    //...
    int testScoreStuden30{};
    */
    /*
    Arrays give us a much easier way to do this. The following array definition is essentially equivalent:
    */

    int testScore[30]{};// allocate 30 integer variables in a fixed array

    /*----------------------------------
        Array elements and subscripting
    -----------------------------------*/
    /*
    Important: Unlike everyday life, where we typically count starting from 1, in C++, arrays 
    always count starting from 0!
    */

    /*----------------------------------
        An example array program
    -----------------------------------*/
    /*
    Here’s a sample program that puts together the definition and indexing of an array:
    */

    int prime[5]{};// hold the first 5 prime numbers
    prime[0] = 2; // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;   
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 prime number is: " << prime[0] + prime[1] + prime[2]
    + prime[3] + prime[4] << '\n';

    /*----------------------------------
                Array data types
    -----------------------------------*/
    /*
    Arrays can be made from any data type. Consider the following example, where we 
    declare an array of doubles:
    */

    double batteryLifeInHours[3]{};// allocate 3 doubles
    batteryLifeInHours[0] = 2.0;
    batteryLifeInHours[1] = 3.0;
    batteryLifeInHours[2] = 4.3;

    std::cout << "The average battery life is " << (batteryLifeInHours[0] + batteryLifeInHours[1] + 
    batteryLifeInHours[2]) / 3.0 << "hour(s)\n";


    /*----------------------------------
                Array inside struct
    -----------------------------------*/
    /*
    Arrays can also be made from structs. Consider the following example:
    */   

    struct Rectangle
    {
        int length{};
        int width{};
    };

    Rectangle rects[5]{};// declare an array of 5 Rectangle

    /*
    To access a struct member of an array element, first pick which array element you want, 
    and then use the member selection operator to select the struct member you want:
    */

    rects[0].length = 24;

    /*----------------------------------
                Array subscripts
    -----------------------------------*/
    int array[5]{};// declare an array of length 5

    //You can using a literal (constant) index:
    array[1] = 7;// ok

    //You can using an enum (constant) index
    enum Animals
    {
        animal_cat = 2
    };
    array[animal_cat] = 4;// ok

    // You can using a variable (non-constant) index:
    short index{ 3 };
    array[index] =  7;// ok

    // You can using an expression that evaluates to an integer index:
    array[1+2] = 7; // ok

    /*----------------------------------
            Fixed array declarations
    -----------------------------------*/
    /*
    When declaring a fixed array, the length of the array (between the square brackets) 
    must be a compile-time constant.
    */

    //We can using a literal constant
    int numberOfLessonPerDay1[7]{}; // ok

    //We can using a constexpr symbolic constant
    constexpr int daysPerWeek1{ 7 };
    int numberOfLessonPerDay2[daysPerWeek1]{}; // ok

    //We can using an enumerator
    enum Weekend
    {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday,

        maxWeekDay
    };
    int numberOfLessonPerDay3[maxWeekDay]{}; // ok

    //Note that non-const variables or runtime constants cannot be used:
    int daysPerWeek2{};
    std::cin >> daysPerWeek2;
    int numberOfLessonPerDay4[daysPerWeek2]{};// Not ok -- daysPerWeek is not a compile-time constant!

    /*----------------------------------
            A note on dynamic arrays
    -----------------------------------*/
    /*
    Because fixed arrays have memory allocated at compile time, that introduces two limitations:

    Fixed arrays cannot have a length based on either user input or some other value calculated at 
    runtime.
    Fixed arrays have a fixed length that can not be changed.

    In many cases, these limitations are problematic. Fortunately, C++ supports a second kind 
    of array known as a dynamic array. The length of a dynamic array can be set at runtime, 
    and their length can be changed. However, dynamic arrays are a little more complicated to 
    instantiate, so we’ll cover them later in the chapter.
    */
    return 0;
}