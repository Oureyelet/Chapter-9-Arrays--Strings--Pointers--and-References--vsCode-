#include <iostream>
#include <iterator>

int main()
{
    std::cout << "Yo yo yo!" << '\n';

    /*--------------------
    Multidimensional array
    --------------------*/
    int array[3][5];// a 3-element array of 5-element arrays
    /*
    Conceptually, the above two-dimensional array is laid out as follows:
    [0][0]  [0][1]  [0][2]  [0][3]  [0][4] // row 0
    [1][0]  [1][1]  [1][2]  [1][3]  [1][4] // row 1
    [2][0]  [2][1]  [2][2]  [2][3]  [2][4] // row 2
    */
    //To access the elements of a two-dimensional array, simply use two subscripts:
    array[2][3] = 7;

    /*---------------------------------
    Initializing two-dimensional arrays
    ---------------------------------*/
    int array1[3][5]
    {
        {1, 2, 3, 4, 5}, // row 0
        {6, 7, 8, 9, 10},// row 1
        {11, 12, 13, 14, 15}// row 2
    };
    int numRows{ sizeof(array1) / sizeof(array1[0]) };
    int numCols{ sizeof(array1[0]) / sizeof(array1[0][0]) };

    /*-------------------------------------------
    Accessing elements in a two-dimensional array
    -------------------------------------------*/
    for(int row{ 0 }; row < numRows; ++row)// step through the rows in the array
    {
        for(int col{ 0 }; col < numCols; ++col)// step through each element in the row
        {
            std::cout << array1[row][col] << ' ';
        }
    }
    std::cout << '\n';

    /*------------------------------------------------
    Multidimensional arrays larger than two dimensions
    ------------------------------------------------*/
    int array3[3][5][10];  
    /*
    Three-dimensional arrays are hard to initialize in any kind of intuitive way using 
    initializer lists, so it’s typically better to initialize the array to 0 and explicitly 
    assign values using nested loops.
    */

    /*-----------------------------
    A two-dimensional array example
    -----------------------------*/
    //Let’s take a look at a practical example of a two-dimensional array:

    constexpr int numRows2{ 11 };
    constexpr int numCols2{ 11 };

    int product[numRows2][numCols2]{};

    for(int row{ 1 }; row < numRows2; ++row)
    {
        for(int col{ 1 }; col < numCols2; ++col)
        {
            product[row][col] = row * col;
        }
    }

    for(int row{ 1 }; row < numRows2; ++row)
    {
        for(int col{ 1 }; col < numCols2; ++col)
        {
            std::cout << product[row][col] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}