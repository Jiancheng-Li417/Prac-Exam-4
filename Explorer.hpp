#ifndef EXPLORER_HPP
#define EXPLORER_HPP

#include "GridItem.hpp"

class Explorer : public GridItem {
private:
    int stamina;

public:
    Explorer(int gridWidth, int gridHeight)
        : GridItem(0, 0, gridWidth, gridHeight), stamina(2) {}

    int getStamina() {
        return stamina;
    }

    void jumpIt() {
        if (stamina > 0) {
            stamina--;
        }
    }

    bool move(int xOffset, int yOffset) {
        if ((xOffset != 0 && yOffset != 0) || (xOffset == 0 && yOffset == 0)) {
            return false; // Invalid move
        }
        // Check grid boundaries
        if (getCoordinates().first + xOffset < 0 || getCoordinates().first + xOffset >= getGridWidth() ||
            getCoordinates().second + yOffset < 0 || getCoordinates().second + yOffset >= getGridHeight()) {
            return false; // Out of bounds
        }
        setCoordinates(getCoordinates().first + xOffset, getCoordinates().second + yOffset);
        return true;
    }
};

#endif // EXPLORER_HPP
