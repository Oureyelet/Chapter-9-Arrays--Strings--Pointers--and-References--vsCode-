#include <iostream>
#include <iterator> // for std::size
 
int main()
{
    constexpr int scores[]{ 84, 92, 76, 811, 567 };
    int numScores{ sizeof(scores) / sizeof(scores[0]) };
 
    int maxScore{ 0 }; // Assume our largest score is 0 to start
    int index{ 0 }; // tast from question 3
 
    // now look for a larger score in the full array
    for(int student{ 0 }; student < numScores; ++student)
    {
        if(scores[student] > maxScore)
        {
            maxScore = scores[student];
        }
    }

    for(int count{ 0 }; count < numScores ;++count)
    {
        if(scores[count] == maxScore)
        {
            index = count;
        }
    }
 
    std::cout << "The best score was " << maxScore << '\n';
    std::cout << "Index of the largest score is " << index << '\n';
 
    return 0;
}