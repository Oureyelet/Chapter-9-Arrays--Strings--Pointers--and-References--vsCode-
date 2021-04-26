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

    rects[0].length = 24

    return 0;
}