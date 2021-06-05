#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iterator>

std::string askUser()
{
    std::string choice;
    std::cout << "Enter a name (for see if the name is in system): ";
    std::getline (std::cin,choice);

    return choice;
}

void find_a_name(std::string choice, std::string array)
{
    for(auto& count : array)
    {
        if(choice == array)
        {
            std:: cout << count << " was found." << '\n';
            
        }
        else
        {
            std:: cout << count << " was not found." << '\n';
            
        }
       std::cout << array << ' ';
    }
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

    std::string choice;
    std::cout << "Enter a name (for see if the name is in system): ";
    std::getline (std::cin,choice);

    auto it = std::find(std::begin(names), std::end(names), choice);

    for(int count{ 0 }; auto& name : names)
    {
        if( it != std::end(names) )
        {
            std::cout << "mamy" << ' ';
            break;
        }
        
        else
        {
            std::cout << "nie ma " << ' ';
            break;
        }
        
        ++count;
    }
    std::cout << '\n';




    return 0;
}