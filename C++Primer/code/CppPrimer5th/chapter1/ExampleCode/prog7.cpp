#include <iostream>
#include "Sales_item.h"

int main() {

    // Sales_item book;
    // std::cin >> book;
    // std::cout << book << std::endl;

    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;

    return 0;
}