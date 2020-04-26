#include "Game.hpp"
#include <Arduino.h>

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

void Game::applyPositionsToGrid()
{
    /* int snakeX = _snake.getX(); */
    /* int snakeY = _snake.getY(); */

    /* int AppleX = _apple.getX(); */
    /* int AppleY = _apple.getY(); */

    for (int i = 0; i < 8; i++) {
        _grid[i] = 0b00000000;
        /* if (snakeX] == i) */

    }



}

void Game::start()
{
    while (1) {
        _snake.move();
        applyPositionsToGrid();
        _ledmatrix.displayGrid(_grid);

        delay(250);
    }
}

void Game::updateEvents()
{
    _snake.setDirection(_controller.getEvent());
}
