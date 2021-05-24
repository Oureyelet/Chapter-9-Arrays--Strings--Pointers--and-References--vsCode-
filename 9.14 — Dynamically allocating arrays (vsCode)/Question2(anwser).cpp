#include <iostream>
#include <algorithm>// std::sort
#include <cstddef>// std::size_t
#include <limits>// std::numeric_limits
#include <string>

using namespace std;

//forward functions declaration
size_t getNameCount();
void getNames(string*,size_t);
void printNames(string*,size_t);

int main()
{
    std::size_t lenght{ getNameCount() };

    auto* names{ new std::string[lenght]{} };

    getNames(names, lenght);

    std::sort(names, names + lenght);

    printNames(names, lenght);

    delete[] names;


    return 0;
}

std::size_t getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t how_many{};
    std::cin >> how_many;

    return how_many;
}

// Asks user to enter all the names
void getNames(std::string* names, std::size_t how_many)
{
    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(std::size_t count{ 0 }; count < how_many; ++count)
    {
        std::cout << "Enter name #" << count+1 << ": ";
        std::getline(std::cin, names[count]); // ????       
    }
}

// Prints the sorted names
void printNames(std::string* names, std::size_t how_many)
{
    std::cout << "\nHere is your sorted list:\n";

    for(std::size_t count{ 0 }; count < how_many; ++count)
    {
        std::cout << "Name #" << count+1 << ": " << names[count] << '\n';
    }
}