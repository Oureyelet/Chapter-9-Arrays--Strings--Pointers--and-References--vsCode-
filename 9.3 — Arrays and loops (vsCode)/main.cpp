#include <iostream>
#include <iterator> // for std::size (ONLY C++17)
#include <limits> // for numeric_limits

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

    constexpr int scoresC[]{34, 445, 34, 67, 7};
    constexpr int numStudentsC{ sizeof(scoresC) / sizeof(scoresC[0]) }; // Numbers of students (5)

    int maxScore{ 0 }; // keep track of our largest score

    for(int count{ 0 }; count < numStudentsC; ++count)
    {
        if(scoresC[count] > maxScore)
        {
            maxScore = scoresC[count];
        }
    }

    std::cout << "The best score was: " << maxScore << '\n';

    /*
    In this example, we use a non-loop variable called maxScore to keep track of the 
    highest score we’ve seen. maxScore is initialized to 0 to represent that we have not seen 
    any scores yet. We then iterate through each element of the array, and if we find 
    a score that is higher than any we’ve seen before, we set maxScore to that value. 
    Thus, maxScore always represents the highest score out of all the elements we’ve searched so far. 
    By the time we reach the end of the array, maxScore holds the highest score in the entire array.
    */

    /*-------------------------------------------
                Mixing loops and arrays
    --------------------------------------------*/
    /*
    Loops are typically used with arrays to do one of three things:
    1) Calculate a value (e.g. average value, total value)
    2) Search for a value (e.g. highest value, lowest value).
    3) Reorganize the array (e.g. ascending order, descending order)
    */

    /*-------------------------------------------
                    Quiz time !
    --------------------------------------------*/
    /*
    Question #1

    Print the following array to the screen using a loop:
        1 constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    Hint: You can use std::size (as of C++17) or the sizeof() trick (prior to C++17) 
    to determine the array length.
    */
    int array_Q1[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int numArray_Q1{ sizeof(array_Q1) / sizeof(array_Q1[0]) };

    for(int count{ 0 }; count < numArray_Q1; ++count)
    {
        std::cout << array_Q1[count] << " ";
    }

    std::cout << '\n';

    /*
    Question #2

    Given the array in question 1:

    Ask the user for a number between 1 and 9. If the user does not enter a number 
    between 1 and 9, repeatedly ask for an integer value until they do. Once they have 
    entered a number between 1 and 9, print the array. Then search the array for the value 
    that the user entered and print the index of that element.

    You can test std::cin for invalid input by using the following code:

    // if the user entered something invalid
    if (std::cin.fail())
    {
        std::cin.clear(); // reset any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
    }
    */


    while(true)
    {
        std::cout << "Enter an integer number between 1 and 9: ";
        int choice{ 0 };
        std::cin >> choice;

        if(std::cin.fail() )// has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else if(true)
        {
            switch(choice)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                {
                    for(int count{ 0 }; count < numArray_Q1; ++count)
                    {
                        std::cout << array_Q1[count] << " ";
                    }
                    std::cout << '\n';
                    int index{ 0 };
                    for(int count{ 0 }; count < numArray_Q1; ++count)
                    {
                        if(array_Q1[count] = choice)
                        {
                            index = count;
                        }
                    }
                            std::cout << "Index of this array is: " << index << '\n';
                    return choice;
                }
                default:
                    std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
        }
        else// else our extraction succeeded
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(int count{ 0 }; count < numArray_Q1; ++count)
            {
                std::cout << array_Q1[count] << " ";
            }
            std::cout << '\n';
            int index{ 0 };
            for(int count{ 0 }; count < numArray_Q1; ++count)
            {
                if(array_Q1[count] = choice)
                {
                    index = count;
                }
            }
                    std::cout << "Index of this array is: " << index << '\n';
            return choice;// so return the value we extracted
        }

    }// and try again

    return 0;   
}