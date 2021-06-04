#include <iostream>
#include <iterator> // for std::size
#include <string>
#include <vector>

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents{ std::size(scores) };

    int maxScores{ 0 };// keep track of our largest score

    for(int count{ 0 }; count < numStudents; ++count)
    {
        if(scores[count] > maxScores)
        {
            maxScores = scores[count];
        }
    }

    std::cout << "The best score was " << maxScores << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loop (also called a range-based for-loop)" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The for-each statement has a syntax that looks like this:

    for (element_declaration : array)
        statement;
    */
    // ! ! ! element_declaration should have the same type as the array elements ! ! !
    // !!! the element declaration should ideally be a reference. !!!

    /*
    Let’s take a look at a simple example that uses a for-each loop to print all 
    of the elements in an array named fibonacci:
    */
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for(int count : fibonacci)// iterate over array fibonacci
    {
        std::cout << count << ' ';// we access the array element for this iteration through variable number
    }
    std::cout << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For each loops and the auto keyword" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Our above example with auto keword:

    for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops and references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    //In the following for-each example, our element declarations are declared by value:
    std::string our_string[]{ "peter", "likes", "frozen", "yogurt" };
    for(auto count : our_string)// element will be a copy of the current array element
    {
        std::cout << count << ' ';
    }
    std::cout << '\n';

    /*
    This means each array element iterated over will be copied into variable element. 
    Copying array elements can be expensive, and most of the time we really just want 
    to refer to the original element. Fortunately, we can use references for this:
    */
    std::string our_string_2[]{ "peter", "likes", "frozen", "yogurt" };
    for(auto& count : our_string_2)// The ampersand makes element a reference to the actual array element, preventing a copy from being made
    {
        std::cout << count << ' ';
    }
    std::cout << '\n';

    /*
    And, of course, it’s a good idea to make your reference const if you’re 
    intending to use it in a read-only fashion.
    */

    /*
    Best practice

    In for-each loops element declarations, if your elements are non-fundamental types, 
    use references or const references for performance reasons.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Rewriting the max scores example using a for-each loop" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    //Here’s the example at the top of the lesson rewritten using a for each loop:

    constexpr int scores_2[]{ 84, 92, 76, 811, 56 };
    int maxScores_2{ 0 };// keep track of our largest score

    for(auto count : scores_2)// iterate over array scores, assigning each value in turn to variable score
    {
        if(count > maxScores_2)
        {
            maxScores_2 = count;
        }
    }
    std::cout << "The best score was " << maxScores_2 << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops and non-arrays" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    For-each loops don’t only work with fixed arrays, they work with many kinds of list-like 
    structures, such as vectors (e.g. std::vector), linked lists, trees, and maps. We haven’t 
    covered any of these yet, so don’t worry if you don’t know what these are. Just remember 
    that for each loops provide a flexible and generic way to iterate through more than just arrays.
    */
    std::vector fibonacci_2{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    // note use of std::vector here rather than a fixed array
    // Before C++17
    // std::vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 
    for(auto count : fibonacci_2)
    {
        std::cout << count << ' ';
    }
    std::cout << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each doesn’t work with pointers to an array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In order to iterate through the array, for-each needs to know how big the array is, 
    which means knowing the array size. Because arrays that have decayed into a pointer 
    do not know their size, for-each loops will not work with them!
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Can I get the index of the current element?" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    //For-each loops do not provide a direct way to get the array index of the current element.
    //Since C++20, range-based for-loops can be used with an init-statement just 
    //like the init-statement in if-statements.

    /*
    The init-statement is placed right before the loop variable:

    for (init-statement; element_declaration : array)
        statement;
    */
    // !!! the element declaration should ideally be a reference. !!!
    std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" };// Names of the students
    constexpr int scores_7[]{ 84, 92, 76, 81, 56 };
    int maxScores_7{ 0 };

    for(int count{ 0 }; auto& count_array : scores_7)// count is the index of the current element
    {
        if(count_array > maxScores_7)
        {
            std::cout << names[count] << " beat the previous best score of " << maxScores_7 << " by " <<
            (count_array - maxScores_7) << " points!\n";
            maxScores_7 = count_array;
        }
    
        ++count;
    }
    
    std::cout << "The best score was " << maxScores_7 << '\n';


    
    
    return 0;
}