#include <iostream>
#include <string>
#include <string_view>

std::string askUser()
{
    std::cout << "enter a name :";
    std::string choice{};
    std::getline(std::cin, choice);

    return choice;
}

int main()
{
    std::string_view arr[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::string choice{ askUser() };
 

    bool found{ false };

    for(auto& array : arr )
    {
        if(choice == array)
        {
            found = true;
            break;
        }
    }

    if(found) // same as = if(found == true)
    {
        std::cout << "Yep !" << '\n';
    }
    else
    {
        std::cout << "nope." << '\n';
    }

    return 0;
}