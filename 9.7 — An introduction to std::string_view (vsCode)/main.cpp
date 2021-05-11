#include <iostream>
#include "functions.h" 
#include <string> // for std::string
#include <string_view> // for string_view
#include <iterator> // for size
#include <cstring> // For std::strlen and C-Style


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

    /*--------------------------
    functions std::string_view
    --------------------------*/
    std::string_view str_3{ "Trains are fast!" };

    std::cout << str_3.length() << '\n'; //16
    std::cout << str_3.substr(0, str.find(' ')) << '\n'; //Trains
    std::cout << (str_3 == "Trains are fast!") << '\n'; // 1

    std::cout << str_3 << '\n';

    //--------------------------

    char arr[]{ "Gold" };
    std::string_view str_4{ arr };

    std::cout << str_4 << '\n';// Gold

    // Change 'd' to 'f' in arr
    arr[3] = 'f';
    
    std::cout << str_4 << '\n';// Golf

    /*
    Best practice:

    Use std::string_view instead of C-style strings.

    Prefer std::string_view over std::string for read-only strings, 
    unless you already have a std::string.
    */

    /*--------------------------
    View modification functions
    --------------------------*/
    std::string_view peach{ "Peach" };

    std::cout << peach << '\n';

    // Ignore the first character.
    peach.remove_prefix(1);

    std::cout << peach << '\n';

    // Ignore the last 2 characters.
    peach.remove_suffix(2);

    std::cout << peach << '\n';

    /*
    Unlike real curtains, a std::string_view cannot be opened back up. 
    Once you change the visible area, you can’t go back (There are tricks which we won’t go into).
    */

    /*-----------------------------------------------------
    std::string_view works with non-null-terminated strings
    -----------------------------------------------------*/
    // No null-terminator.
    char vowels[]{'a', 'e', 'i', 'o', 'u'};

    // vowels isn't null-terminated. We need to pass the length manually.
    // Because vowels is an array, we can use std::size to get its length.

    std::string_view str_5{ vowels, std::size(vowels) };

    std::cout << str_5 << '\n';// This is safe. std::cout knows how to print std::string_views.

    /*--------------
    Ownership issues
    --------------*/
    askForName();

    std::string_view view{ askForName() };// view is observing a string that already died.

    std::cout << "Your name is: " << view << '\n';
    /*
    Warning

    Make sure that the underlying string viewed with a std::string_view does 
    not go out of scope and isn’t modified while using the std::string_view.
    */

    /*--------------------------------------------
    Converting a std::string_view to a std::string
    --------------------------------------------*/
    //An std::string_view will not implicitly convert to a std::string, but can be explicitly converted:
    std::string_view vs{ "Balloon" };

    vs.remove_suffix(3);

    std::cout << vs << '\n';

    // print(sv); // compile error: won't implicitly convert

    std::string str_6{ vs }; //ok

    print(str_6);   //ok

    print(static_cast<std::string>(vs)); //ok

    /*-----------------------------------------------
    Converting a std::string_view to a C-style string
    -----------------------------------------------*/
    std::string_view eloBelo{ "Plane" };

    eloBelo.remove_suffix(3);

    // Create a std::string from the std::string_view
    std::string gitgit{ eloBelo };

    // Get the null-terminated C-style string.
    const char* szNullTerminated{ gitgit.c_str() };

    // Pass the null-terminated string to the function that we want to use.
    std::cout << gitgit << " has " << std::strlen(szNullTerminated) << " letter(s)\n";
    /*
    However, creating a std::string every time we want to pass a std::string_view as 
    a C-style string is expensive, so this should be avoided if possible.
    */

    /*------------------------------------------------
    Opening the window (kinda) via the data() function
    ------------------------------------------------*/
    std::string_view apple{ "Apple" };

    std::cout << apple << '\n';

    /*
    We use std::strlen because it's simple, this could be any other function
    that needs a null-terminated string.
    It's okay to use data() because we haven't modified the view, and the
    string is null-terminated.
    */

    std::cout << std::strlen(apple.data()) << '\n';

    /*-----------------------
    Incomplete implementation
    -----------------------*/
    std::string One_1{ "Hello" };
    std::string_view Two_2{ "World" };

    //Doesn't word
    /*
    std::cout << ( One_1 + Two_2 ) << '\n';
    std::cout << ( Two_2 + One_1 ) << '\n';
    */

    /*
    Potentially unsafe, or not what we want, because we're treating
    the std::string_view as a C-style string.
    */
    std::cout << (One_1 + Two_2.data()) << '\n';
    std::cout << (Two_2.data() + One_1 ) << '\n';

    // Ok, but ugly and wasteful because we have to construct a new std::string.
    std::cout << (One_1 + std::string{ Two_2 }) << '\n';
    std::cout << (std::string{ Two_2 } + One_1) << '\n';
    std::cout << (One_1 + static_cast<std::string>(Two_2)) << '\n';
    std::cout << ( static_cast<std::string>(Two_2) + One_1) << '\n';

    return 0;
}