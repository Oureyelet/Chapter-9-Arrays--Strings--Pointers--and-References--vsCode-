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

unsigned int PRNG()
{
    static unsigned int seed{ 5323 };
    seed = 8253729 * seed + 2396403;

    return seed % 2;
}

bool playBlackjack(deck_type& x)
{
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(x.begin(), x.end(), mt);

    std::cout << '\n';

    
    std::cout << "The dealer gets one card to start: ";
    

    return true;
}

int main()
{
    auto deck{ createDeck() };

    printDeck(deck);

    std::cout << "After shuffle..." << '\n';

    playBlackjack(deck);


    std::cout << deck;

    return 0;
}


/*
Question #7

a) Alright, challenge time! Let’s write a simplified version of Blackjack. If you’re not already 
familiar with Blackjack, the Wikipedia article for Blackjack has a summary.

Here are the rules for our version of Blackjack:

    The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it 
    doesn’t matter at this point).
    The player gets two cards to start.
    The player goes first.
    A player can repeatedly “hit” or “stand”.
    If the player “stands”, their turn is over, and their score is calculated based on the cards they 
    have been dealt.
    If the player “hits”, they get another card and the value of that card is added to their total score.
    An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, 
    we’ll count it as an 11 here.
    If the player goes over a score of 21, they bust and lose immediately.
    The dealer goes after the player.
    The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
    If the dealer goes over a score of 21, they bust and the player wins immediately.
    Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player 
    loses (we’ll consider ties as dealer wins for simplicity).

In our simplified version of Blackjack, we’re not going to keep track of which specific cards the player 
and the dealer have been dealt. We’ll only track the sum of the values of the cards they have been dealt 
for the player and dealer. This keeps things simpler.

Start with the code you wrote in quiz #6. Create a function named playBlackjack(). This function should:

    Accept a shuffled deck of cards as a parameter.
    Implement Blackjack as defined above.
    Returns true if the player won, and false if they lost. 

Also write a main() function to play a single game of Blackjack.
*/