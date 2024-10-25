#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>
#include <tuple>
#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"

enum GameState {
    WIN,
    LOSE,
    PLAYING
};

class Game {
private:
    int width, height;
    Explorer* player;
    Exit* exit;
    std::vector<Pit*> pits;
    GameState state;

public:
    Game(int width, int height, std::vector<std::tuple<int, int>> pitCoordinates)
        : width(width), height(height), state(PLAYING) {
        player = new Explorer(width, height);
        exit = new Exit(width, height);
        for (auto& coords : pitCoordinates) {
            int x = std::get<0>(coords);
            int y = std::get<1>(coords);
            if ((x != 0 || y != 0) && (x != width - 1 || y != height - 1)) {
                pits.push_back(new Pit(x, y, 1, 1));
            }
        }
    }

    bool displayState() {
        switch (state) {
        case WIN:
            std::cout << "You win!" << std::endl;
            return true;
        case LOSE:
            std::cout << "You lose :(" << std::endl;
            return true;
        case PLAYING:
            std::cout << "Game on" << std::endl;
            return false;
        }
        return false;
    }

    void movePlayer(int dx, int dy) {
        if (state == PLAYING) {
            if (player->move(dx, dy)) {
                for (auto pit : pits) {
                    if (pit->interact(player)) {
                        state = LOSE;
                        break;
                    }
                }
                if (exit->interact(player)) {
                    state = WIN;
                }
            }
        }
    }

    void printGrid() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == std::get<0>(exit->getCoordinates()) && y == std::get<1>(exit->getCoordinates())) {
                    std::cout << 'E';
                }
                else if (x == std::get<0>(player->getCoordinates()) && y == std::get<1>(player->getCoordinates())) {
                    std::cout << 'X';
                }
                else if (std::any_of(pits.begin(), pits.end(), [&](Pit* pit) {
                    return x == std::get<0>(pit->getCoordinates()) && y == std::get<1>(pit->getCoordinates());
                    })) {
                    std::cout << 'P';
                }
                else {
                    std::cout << '_';
                }
            }
            std::cout << std::endl;
        }
    }

    ~Game() {
        delete player;
        delete exit;
        for (auto pit : pits) {
            delete pit;
        }
    }
};

#endif // GAME_HPP
