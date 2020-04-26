#include "Game.hpp"

Game::Game()
{

}

void Game::reset()
{
    _snake.reset();
    _apple.changePosition();
    for (int i = 0; i < GRID_SIZE; i++) {
        _grid[i] = 0b00000000;
    }
}

void Game::start()
{
    while (1) {



    }
}

void Game::updateEvents()
{

}
