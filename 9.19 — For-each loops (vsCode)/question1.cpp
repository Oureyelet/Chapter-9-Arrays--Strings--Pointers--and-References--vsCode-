#include <iostream>
#include <string>

std::string askUser()
{
    std::string choice;
    std::cout << "Enter a name (for see if the name is in system): ";
    std::cin >> choice;

    return choice;
}

std::string_view find_a_name(std::string choice, std::string_view array)
{
    for(auto& count : array)
    {
        if(choice == array)
        {
            std:: cout << choice << " was found." << '\n';
            return choice;
        }
        else
        {
            std:: cout << choice << " was not found." << '\n';
            return choice;
        }
    }
    return choice;
}

int main()
{
    /*
    Question #1

    Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, 
    Fred, Greg, and Holly. Ask the user to enter a name. Use a for each loop to see if the name 
    the user entered is in the array.

    Sample output:

    Enter a name: Betty
    Betty was found.

    Enter a name: Megatron
    Megatron was not found.

    Hint: Use std::string_view as your array type.
    */

    std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    find_a_name(askUser(),*names);




    return 0;
}