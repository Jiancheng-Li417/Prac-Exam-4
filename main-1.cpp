#include <iostream>
#include "GridItem.hpp"
#include "Helper.hpp"

int main() {
    GridItem item1(1, 1, 10, 10);
    GridItem item2(2, 2, 10, 10);

    std::cout << "GridItem active count: " << GridItem::getActiveGridItemCount() << std::endl;

    auto coords = item1.getCoordinates();
    std::cout << "Item1 Coordinates: (" << std::get<0>(coords) << ", " << std::get<1>(coords) << ")" << std::endl;

    std::tuple<int, int> point1 = std::make_tuple(2, 3);
    std::tuple<int, int> point2 = std::make_tuple(5, 7);
    std::cout << "Absolute Squared Distance: " << Helper::absoluteSquaredDistance(point1, point2) << std::endl;

    return 0;
}
