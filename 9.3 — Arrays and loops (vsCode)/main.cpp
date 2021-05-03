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

    int numStudentA[]{34, 45, 34, 67, 77};

    int totalScoreA{ numStudentA[0] + numStudentA[1] + numStudentA[2] + numStudentA[3] + numStudentA[4] };
    auto averageScoreA{ static_cast<double>(totalScoreA)/ 5 /*std::size(totalScoreA) (ONLY C++17) */ };

    std::cout << averageScoreA << '\n';



    return 0;   
}