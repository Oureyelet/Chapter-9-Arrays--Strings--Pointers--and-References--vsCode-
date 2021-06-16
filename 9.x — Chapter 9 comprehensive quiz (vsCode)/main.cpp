#include <algorithm> // std::shuffle
#include <array>
#include <ctime>
#include <iostream>
#include <numeric> // std::reduce
#include <random>

enum items
{
    health_potion = 2,
    torche = 5, 
    arrow = 10
};

void countTotalItems()
{

    std::array<int,3> q1{ health_potion, torche, arrow };
    
    std::cout << "Total item is: " << std::reduce(q1.begin(), q1.end()) << '\n';
    std::cout << "number of torches: " << q1[1] << '\n';

}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    To make the quizzes a little easier, we have to introduce a couple of new algorithms.
    */
    /*
    std::reduce applies a function, by default the + operator, to all elements in a list, resulting 
    in a single value. When we use the + operator, the result is the sum of all elements in the list. 
    Note that there’s also std::accumulate. std::accumulate cannot be parallelized, because it applies 
    the function left-to-right. std::reduce segments the list, which means that the function is applied 
    in an unknown order, allowing the operation to be parallelized. If we want to sum up a list, 
    we don’t care about the order and we use std::reduce.
    */
    /*
    Author's note

    std::reduce is currently not fully implemented in all major standard libraries. 
    If it doesn’t work for you, fall back to std::accumulate.
    */
    /*
    std::shuffle takes a list and randomly re-orders its elements.
    */
    std::array arr{ 1, 2, 3, 4 };

    std::cout << std::reduce(arr.begin(), arr.end()) << '\n'; // add all array = 10

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(arr.begin(), arr.end(), mt);//shuffle our array

    for(auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Question #1" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, 
    and arrows. Create an enum to identify the different types of items, and an std::array to store 
    the number of each item the player is carrying (The enumerators are used as indexes of the array). 
    The player should start with 2 health potions, 5 torches, and 10 arrows. Write a function called 
    countTotalItems() that returns how many items the player has in total. Have your main() function 
    print the output of countTotalItems() as well as the number of torches.
    */
    
    countTotalItems();


    return 0;
}