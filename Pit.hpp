#ifndef PIT_HPP
#define PIT_HPP

#include "Interactable.hpp"

class Pit : public Interactable {
private:
    bool covered;

public:
    Pit(int x, int y, int width, int height)
        : Interactable(x, y, width, height), covered(false) {}

    bool interact(Explorer* player) override {
        if (Helper::absoluteSquaredDistance(getCoordinates(), player->getCoordinates()) == 0 && !covered) {
            player->jumpIt();
            covered = true;
            return player->getStamina() == 0;
        }
        return false;
    }

    InteractableType getType() override {
        return PIT;
    }
};

#endif // PIT_HPP
