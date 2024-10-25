#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP

#include <tuple>

class GridItem {
private:
    int x, y;
    int width, height;
    static int activeGridItemCount;

public:
    GridItem() : x(0), y(0), width(0), height(0) {
        activeGridItemCount++;
    }

    GridItem(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
        activeGridItemCount++;
    }

    void setCoordinates(int x, int y) {
        this->x = x;
        this->y = y;
    }

    std::tuple<int, int> getCoordinates() {
        return std::make_tuple(x, y);
    }

    int getGridWidth() {
        return width;
    }

    int getGridHeight() {
        return height;
    }

    static int getActiveGridItemCount() {
        return activeGridItemCount;
    }

    virtual ~GridItem() {
        activeGridItemCount--;
    }
};

int GridItem::activeGridItemCount = 0;

#endif // GRIDITEM_HPP
