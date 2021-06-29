#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

enum class Card_Ranks
{
    Two, 
    Three, 
    Four, 
    Five, 
    Six, 
    Seven, 
    Eight, 
    Nine, 
    Ten, 
    Jack, 
    Queen, 
    King, 
    Ace,

    max_ranks
};

enum class Card_Suits
{
    clubs, 
    diamonds, 
    hearts, 
    spades,

    max_suits
};

struct Card
{
    Card_Ranks rank{};
    Card_Suits suit{};
};

void printInitials(const Card& x)
{
    switch(x.rank)
    {
        case Card_Ranks::Two:      std::cout << "2";    break;
        case Card_Ranks::Three:    std::cout << "3";    break;
        case Card_Ranks::Four:     std::cout << "4";    break;
        case Card_Ranks::Five:     std::cout << "5";    break;
        case Card_Ranks::Six:      std::cout << "6";    break;
        case Card_Ranks::Seven:    std::cout << "7";    break;
        case Card_Ranks::Eight:    std::cout << "8";    break;
        case Card_Ranks::Nine:     std::cout << "9";    break;
        case Card_Ranks::Ten:      std::cout << "10";   break;
        case Card_Ranks::Jack:     std::cout << "J";    break;
        case Card_Ranks::Queen:    std::cout << "Q";    break;
        case Card_Ranks::King:     std::cout << "K";    break;
        case Card_Ranks::Ace:      std::cout << "A";    break;
        default:
            std::cout << "?" << '\n';
            break;
    }

    switch(x.suit)
    {
        case Card_Suits::clubs:    std::cout << "C";     break;
        case Card_Suits::diamonds: std::cout << "D";     break;
        case Card_Suits::hearts:   std::cout << "H";     break;
        case Card_Suits::spades:   std::cout << "S";     break;
        default:
            std::cout << "?" << '\n';
            break;
    }
}

// We'll need these many more times, create an aliases.
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

deck_type createDeck()
{
    deck_type deck{};

    // We could initialize each card individually, but that would be a pain.  Let's use a loop.
    //std::array<Card, 52> card ?????? its the same ?
    index_type card{ 0 };

    auto suits{ static_cast<int>(Card_Suits::max_suits) };
    auto ranks{ static_cast<int>(Card_Ranks::max_ranks) };

    for(int suit{ 0 }; suit < suits; ++suit)
    {
        for(int rank{ 0 }; rank < ranks; ++rank)
        {
            deck[card].suit = static_cast<Card_Suits>(suit);
            deck[card].rank = static_cast<Card_Ranks>(rank);
            ++card;
        }
    }


    return deck;
}

void printDeck(const deck_type& deck)
{
    for(const auto& i : deck)
    {
        printInitials(i);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type& x)
{
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(x.begin(), x.end(), mt);

    for(auto& i : x)
    {
        printInitials(i);
        std::cout << ' ';
    }
    std::cout << '\n';
}

int main()
{
    auto deck{ createDeck() };

    printDeck(deck);

    std::cout << "After shuffle..." << '\n';

    shuffleDeck(deck);

    return 0;
}



/*
Let’s pretend we’re writing a card game.

a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks 
(2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). 
Those enumerators will not be used to index arrays.

Show Solution

b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the 
struct.

Show Solution

c) Create a printCard() function that takes a const Card reference as a parameter and prints the card 
rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).

Show Hint

Show Solution

d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, 
and initialize it with one of each card. Do this in a function named createDeck and call createDeck 
from main. createDeck should return the deck to main.

Hint: Use static_cast if you need to convert an integer into an enumerated type.

Show Solution

e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the 
cards in the deck. Use a range-based for-loop. When you can printDeck with the deck you generated in the 
previous task, the output should be

2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD 2H 3H 4H 5H 6H 7H 8H 9H TH 
JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS

If you used different characters, that’s fine too.

Show Solution

f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. Update your main 
function to shuffle the deck and print out the shuffled deck.

Reminder: Only seed your random number generator once.

Show Solution

g) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, 
jack, queen, or king is worth 10. Assume an Ace is worth 11).

Show Solution
*/