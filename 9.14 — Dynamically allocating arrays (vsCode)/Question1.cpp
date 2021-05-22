#include <iostream>
#include <string> // for std::strin
#include <cstring> // for size_t
#include <algorithm> // for sort
#include <limits> // for getline
#include <iomanip> // for std::ws

int main()
{

    std::cout << "How many names would you like to enter? :";
    std::size_t how_many{};
    std::cin >> how_many;

    std::string* arrayNames{ new std::string[how_many]{} };
    for(std::size_t count{ 1 }; count < how_many+1; ++count)
    {
        std::cout << "Enter name #" << count << ": ";
        std::getline( std::cin >> std::ws, arrayNames[count-1] );
    }
    std::cout << std::endl;

    std::cout << "Here is your sorted list:" << '\n';

    std::sort(arrayNames, arrayNames + how_many);

    for(std::size_t count{ 1 }; count < how_many+1; ++count)
    {
        std::cout << "Name #" << count << ": " << arrayNames[count-1] << '\n';
    }
    std::cout << std::endl;

    return 0;
}