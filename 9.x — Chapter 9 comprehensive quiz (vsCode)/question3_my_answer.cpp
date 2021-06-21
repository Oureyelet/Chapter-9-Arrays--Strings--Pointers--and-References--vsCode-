#include <iostream>
#include <utility>

void swap_value(int& x,int& y)
{
    std::cout << "Before swap: x = " << x << " and " << " y = " << y << '\n';

    std::swap(x, y); // swap the values of x and y

    std::cout << "After swap: x = " << x << " and " << " y = " << y << '\n';
}

int main()
{
    
    int x{ 2 };
    int y{ 7 };
    

    swap_value(x,y);

    

    return 0;
}

/*
Question #3

Write your own function to swap the value of two integer variables. Write a main() 
function to test it.

Use reference parameters
1
	
void swap(int& a, int& b)
*/