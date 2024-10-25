#ifndef EXIT_HPP
#define EXIT_HPP

#include "Interactable.hpp"
#include "Helper.hpp"

class Exit : public Interactable {
public:
    Exit(int width, int height) : Interactable(width - 1, height - 1, 1, 1) {}

    bool interact(Explorer* player) override {
        return Helper::absoluteSquaredDistance(getCoordinates(), player->getCoordinates()) == 0;
    }

    InteractableType getType() override {
        return EXIT;
    }
};

#endif // EXIT_HPP
