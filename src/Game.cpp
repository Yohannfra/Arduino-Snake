#include "Game.hpp"

#include <Arduino.h>

Game::Game() : _ledmatrix(PIN_CLK_MATRIX, PIN_CS_MATRIX, PIN_DIN_MATRIX)
{
}

void Game::changeApplePosition()
{
    do {
        _apple.changePosition();
        if (_snake.isOnSnakeBody(_apple.getX(), _apple.getY()) == false)
            break;
    } while (1);
}

void Game::reset()
{
    for (int i = 0; i < 2; i++) {
        _ledmatrix.setAllMatrix(HIGH);
        delay(300);
        _ledmatrix.setAllMatrix(LOW);
        delay(300);
    }
    _snake.reset();
    changeApplePosition();
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
        _grid[snakeBody[i].x] = _grid[snakeBody[i].x] ^ (1 << snakeBody[i].y);
    }
    _grid[appleX] = _grid[appleX] ^ (1 << appleY);

    if (appleX == snakeBody[0].x && appleY == snakeBody[0].y) {
        _snake.grow();
        changeApplePosition();
    }
    if (_snake.getSize() > (GRID_SIZE * GRID_SIZE) - 1)
        reset();
}

void Game::start()
{
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
