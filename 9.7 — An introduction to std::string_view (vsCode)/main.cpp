#include <iostream>
#include "functions.h"
#include <string>
#include <string_view>


int main()
{
    message();
    speak();

    char text[]{ "Hello" };
    std::string str{ text };
    std::string more{ str };

    std::cout << text << ' ' << str << ' ' << more << '\n';  
    
    /*--------------------------
    Introducing std::string_view
    --------------------------*/
    std::string_view text_2{ "Hello" }; // view the text "hello", which is stored in the binary
    std::string_view str_2{ text_2 };// view of the same "hello"
    std::string_view more_2{ str_2 };// view of the same "hello"

    std::cout << text_2 << ' ' << str_2 << ' ' << more_2 << '\n';  
    

    return 0;
}