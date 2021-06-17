#include <array>
#include <numeric> // std::reduce
#include <iostream>

enum items
{
    health_potions,
    torches,
    arrows,
    max_items
};

using inventory_type = std::array<int, items::max_items>;

int countTotalItems(const inventory_type& item)
{
    return std::reduce(item.begin(), item.end());
}

int main()
{
    inventory_type arr{ 2, 5, 10 };

    std::cout << "The player has " << countTotalItems(arr) << " item(s) in total.\n";

    // We can access individual items using the enumerators:
    std::cout << "The player has " << arr[items::torches] << " torch(es)\n";


    return 0;
}