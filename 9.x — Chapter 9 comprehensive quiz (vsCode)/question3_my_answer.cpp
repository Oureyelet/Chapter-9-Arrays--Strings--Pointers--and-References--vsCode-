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