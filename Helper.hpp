#ifndef HELPER_HPP
#define HELPER_HPP

#include <tuple>
#include <cmath>

class Helper {
public:
    static double absoluteSquaredDistance(std::tuple<int, int> item1, std::tuple<int, int> item2) {
        int dx = std::get<0>(item1) - std::get<0>(item2);
        int dy = std::get<1>(item1) - std::get<1>(item2);
        return (dx * dx) + (dy * dy);
    }
};

#endif // HELPER_HPP
