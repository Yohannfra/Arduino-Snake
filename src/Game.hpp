#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"
#include "Apple.hpp"
#include "LedMatrix.hpp"
#include "Controller.hpp"

class Game {
    public:
        Game();
        void start();

    private:
        void applyPositionsToGrid();
        void updateEvents();
        void reset();
        Snake _snake;
        Apple _apple;
        LedMatrix _ledmatrix;
        Controller _controller;
        int _grid[GRID_SIZE];
};

#endif // GAME_HPP
