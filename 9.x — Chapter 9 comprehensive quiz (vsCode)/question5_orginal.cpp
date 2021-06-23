#include <iostream>

int main()
{
    /*
    What’s wrong with each of these snippets, and how would you fix it?
    */
    //a) change '<=' for '<' 
    //b) const can't be changed, and pointer have to be lvalue
    /*
    c) for-each loop is only for std::array
    array decays to a pointer when it is passed to printArray(). 
    Range-based for-loops can’t work with a pointer to an array because the size of 
    the array isn’t known. One solution is to add a length parameter to function printArray(), 
    and use a normal for loop. A better solution is to use std::array instead of built-in fixed arrays. 
    */
    //d) yhmmm....
    //e) You can’t make an int pointer point at a non-int variable. ptr should be of type double*. 
 


    return 0;
}