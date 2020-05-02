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
    const snake_part_t  *snakeBody = _snake.getBody();
    unsigned int snakeSize = _snake.getSize();
    int AppleX = _apple.getX();
    int AppleY = _apple.getY();

    for (int i = 0; i < 8; i++) {
        if (i == snakeBody[0].x)
            _grid[i] = (0b00000001) << snakeBody[0].y;
        else
            _grid[i] = (0b00000000);
    }
    /* _grid[0] = (0b00000001) << 3; */
    /* _grid[1] = (0b00000001) << 4; */
}

void Game::start()
{
    while (1) {
        /* _ledmatrix.setAllMatrix(LOW); */
        _snake.setDirection(_controller.getEvent());
        _snake.move();
        applyPositionsToGrid();
        _ledmatrix.displayGrid(_grid);
        delay(250);
    }
}
