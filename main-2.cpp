#include <iostream>
#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"

int main() {
    Explorer explorer(4, 4);
    Exit exit(4, 4);
    Pit pit(1, 1, 1, 1);

    explorer.move(1, 0);
    std::cout << "Explorer moved to (1, 0), Stamina: " << explorer.getStamina() << std::endl;

    if (pit.interact(&explorer)) {
        std::cout << "Explorer fell into the pit!" << std::endl;
    }

    explorer.move(1, 0);
    if (exit.interact(&explorer)) {
        std::cout << "Explorer reached the exit!" << std::endl;
    }

    return 0;
}
