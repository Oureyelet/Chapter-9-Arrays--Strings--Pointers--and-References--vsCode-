#include <iostream>
#include <iterator> // for std::size (ONLY C++17)

int main()
{
    std::cout << "Hello World" << '\n';

    /*-------------------------------------------
                    My own task
    --------------------------------------------*/
    //i gonna try transfer everything in to array.

    int numStudent{ 5 };

    int score0{ 34 };
    int score1{ 45 };
    int score2{ 34 };
    int score3{ 67 };
    int score4{ 77 };

    int totalScore{ score0 + score1 + score2 + score3 + score4 };
    auto averageScore{ static_cast<double>(totalScore) / numStudent };

    std::cout << averageScore << '\n';

    //then i try make equivalent with array :)

    int scoresA[]{34, 45, 34, 67, 77};
    const int numStudentsA{ sizeof(scoresA) / sizeof(scoresA[0]) };

    int totalScoreA{ scoresA[0] + scoresA[1] + scoresA[2] + scoresA[3] + scoresA[4] };
    auto averageScoreA{ static_cast<double>(totalScoreA)/ numStudentsA };

    std::cout << averageScoreA << '\n';

    /*-------------------------------------------
                    Loops and arrays
    --------------------------------------------*/
    //Here’s our example above using a for loop:

    int scoresB[]{34, 45, 34, 67, 77};

    const int numStudentsB{ sizeof(scoresB) / sizeof(scoresB[0]) };

    int totalScoreB{ 0 };

    for(int count{ 0 }; count < numStudentsB; ++count)
    {
        totalScoreB += scoresB[count]; //same: totalScoreB = scoresB[count] + totalScoreB; 
    }

    auto averageScoreB{ static_cast<double>(totalScoreB) / numStudentsB };

    std::cout << averageScoreB << '\n';

    /*
    Here’s an example of using a loop to search an array in order to determine 
    the best score in the class:
    */

    constexpr int scoresC[]{34, 45, 34, 67, 77};
    constexpr int numStudentsC{ sizeof(scoresC) / sizeof(scoresC[0]) };

    int maxScore{ 0 }; // keep track of our largest score

    for(int count{ 0 }; count < numStudentsC; ++count)
    {
        if(scoresC[count] > maxScore)
        {
            maxScore = scoresC[count];
        }
    }

    std::cout << "The best score was: " << maxScore << '\n';




    return 0;   
}