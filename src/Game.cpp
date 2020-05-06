#include "Game.hpp"

#include <Arduino.h>

Game::Game() : _ledmatrix(PIN_CLK_MATRIX, PIN_CS_MATRIX, PIN_DIN_MATRIX)
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
    const snake_part_t *snakeBody = _snake.getBody();
    size_t snakeSize = _snake.getSize();
    int appleX = _apple.getX();
    int appleY = _apple.getY();

    for (size_t i = 0; i < 8; i++)
        _grid[i] = 0;
    for (size_t i = 0; i < snakeSize; i++) {
        if (_grid[snakeBody[i].x] == 0)
            _grid[snakeBody[i].x] = 1 << snakeBody[i].y;
        else
            _grid[snakeBody[i].x] =
                _grid[snakeBody[i].x] ^ (1 << snakeBody[i].y);
    }
    _grid[appleX] = _grid[appleX] ^ (1 << appleY);

    if (appleX == snakeBody[0].x && appleY == snakeBody[0].y) {
        _snake.grow();
        _apple.changePosition();
    }
}

void Game::start()
{
    _apple.changePosition();
    while (1) {
        _snake.setDirection(_controller.getEvent());
        _snake.move();
        if (_snake.eatsItself())
            reset();
        applyPositionsToGrid();
        _ledmatrix.displayGrid(_grid);
        delay(250);
    }
}
