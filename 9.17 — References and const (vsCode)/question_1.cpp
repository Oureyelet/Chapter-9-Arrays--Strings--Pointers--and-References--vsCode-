#include <iostream> 

int main()
{
    std::cout << "Quiz Time!" << '\n';

    /*
    Which of the following types should be passed by value, 
    which by const reference? You can assume that the function which takes these types 
    as parameters doesn’t modify them.

    a) char // NO
    b) std::string // NO
    c) unsigned long // NO
    d) bool // NO
    e) An enumerator // NO

    f) // NO
    struct Position
    {
        double x{};
        double y{};
        double z{};
    };

    g) // NO
    struct Player
    {
        int health{};
        // The Player struct is still under development. More members will be added.
    };

    h) double // NO
    
    i)  
    struct ArrayView // NO
    {
        const int* array{};
        std::size_t length{};
    };
    */

    /*
    Corect anwser:

    a) char is a fundamental type, it should be passed by value.

    b) std::string has to create a copy of the string whenever it is copied. 
    Pass it by const reference.

    c) unsigned long is a fundamental type, it should be passed by value.

    d) bool is a fundamental type, it should be passed by value.

    e) Enumerators (Of enum and enum class) are named integers. They are based on a 
    fundamental type (Usually `int`) and should be passed by value.

    f) Position is a custom type and should be passed by const reference.

    g) Although Player only contains a single int in its current state, which would make 
    it fast to pass by value, more members will be added in the future. We don’t want to 
    update every use of Player when that happens, so we pass it by const reference.

    h) double is a fundamental type, it should be passed by value.

    i) ArrayView only has 2 member variables and no new members will be added in the future. 
    The size of ArrayView will be usually be 16 bytes on 64 bit systems. Although this size isn’t 
    ideal for the processor, it’s still faster to copy ArrayView than passing it by const reference. 
    The type of the array doesn’t matter, because all pointers have the same size. 
    This is also how std::string_view works. In that case, ArrayView::array would be a const char*. 
    Passing ArrayView by const reference wouldn’t be wrong either, because if in doubt, const reference 
    is the way to go. 
    */

    return 0;
}