#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "GridItem.hpp"

enum InteractableType {
    EXIT,
    PIT
};

class Interactable : public GridItem {
protected:
    static int activeInteractableCount;

public:
    Interactable() : GridItem(0, 0, 0, 0) {
        activeInteractableCount++;
    }

    Interactable(int x, int y, int width, int height) : GridItem(x, y, width, height) {
        activeInteractableCount++;
    }

    virtual bool interact(Explorer* player) = 0;
    virtual InteractableType getType() = 0;

    static int getActiveInteractableCount() {
        return activeInteractableCount;
    }

    virtual ~Interactable() {
        activeInteractableCount--;
    }
};

int Interactable::activeInteractableCount = 0;

#endif // INTERACTABLE_HPP
