#include "Snake.hpp"

Snake::Snake()
{

}

void Snake::reset()
{
    _headX = INITIAL_SNAKE_X;
    _headY = INITIAL_SNAKE_Y;
    _size = INITIAL_SNAKE_SIZE;
    _direction = RIGHT;
}
