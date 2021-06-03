#include <iostream>
#include <string>

struct Person
{
    int age{};
    double weight{};
};

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Member selection operator" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    Person osoba{};

    osoba.age = 5;// Member selection using actual struct variable

    //This syntax also works for references:
    Person& ref{ osoba };
    ref.age = 7;

    //However, with a pointer, you need to use the arrow operator:
    Person* ptr{ &osoba };
    ptr->age = 8;

    //The arrow operator does the same as an indirection followed by the . member selection operator:
    (*ptr).weight = 12,5;
    //same as
    ptr->weight = 12,5;

    /*
    Rule !

    When using a pointer to access the value of 
    a member, use operator-> instead of operator. (the . operator)
    */
    Animal puma{ "Puma", { 5 } };

    Animal* pointy{ &puma };

    // pointy is a pointer, use ->
    // paw is not a pointer, use .
    std::cout << pointy->paw.claws << '\n';


    return 0;
}