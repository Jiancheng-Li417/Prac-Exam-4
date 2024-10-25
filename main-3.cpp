#include <iostream>
#include "Game.hpp"

int main() {
    std::vector<std::tuple<int, int>> pits = { std::make_tuple(1, 1), std::make_tuple(2, 2) };
    Game game(4, 4, pits);

    while (!game.displayState()) {
        game.printGrid();
        int dx, dy;
        std::cout << "Enter move (dx dy): ";
        std::cin >> dx >> dy;
        game.movePlayer(dx, dy);
    }

    return 0;
}
