#include <iostream>
#include "function.h"
#include <string>

namespace myNamespace
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        all_animals
    };
}

std::string printName(myNamespace::Animals which)
{
    switch(which)
    {
        case myNamespace::Animals::chicken:
            return "Chicken";
        case myNamespace::Animals::dog:
            return "Dog";
        case myNamespace::Animals::cat:
            return "Cat";
        case myNamespace::Animals::elephant:
            return "Elephant";
        case myNamespace::Animals::duck:
            return "Duck";
        case myNamespace::Animals::snake:
            return "Snake";
        default:
            return 0;
    }
}



int main()
{
    int legs[myNamespace::all_animals]{2, 4, 4, 4, 2};
    print(printName(myNamespace::Animals::snake), legs[myNamespace::Animals::snake]);   

    return 0;
}