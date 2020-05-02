#include "Snake.hpp"

Snake::Snake()
{
    reset();
}

void Snake::reset()
{
    _body[0].x = INITIAL_SNAKE_X;
    _body[0].y = INITIAL_SNAKE_Y;
    _size = INITIAL_SNAKE_SIZE;
    _direction = NONE;
}

void Snake::move()
{
    snake_part_t last;
    snake_part_t tmp;

    for (unsigned int i = 0; i < _size; i++) {
        if (i == 0) { // snake head
            last.x = _body[i].x;
            last.y = _body[i].y;

            _body[i].x += (_direction == RIGHT) ? 1 :
                                (_direction == LEFT) ? -1 : 0;
            _body[i].y += (_direction == DOWN) ? 1 :
                                    (_direction == UP) ? -1 : 0;
        } else { // the rest of the body
            tmp.x = _body[i].x;
            tmp.y = _body[i].y;
            _body[i].x = last.x;
            _body[i].y = last.y;
            last.x = tmp.x;
            last.y = tmp.y;
        }
    }
}

void Snake::setDirection(directions_e newDirection)
{
    if (newDirection != NONE)
        _direction = newDirection;
}

void Snake::grow()
{
    _size += 1;
    if (_size == (GRID_SIZE * GRID_SIZE)) {
        // win annimation
        // reset game
    }
}

bool Snake::eatsItself() const
{
    for (unsigned int i = 0; i < _size; i++) {
        if (i > 0 && _body[i].x == _body[0].x && _body[i].y == _body[0].y)
            return true;
    }
    return false;
}

const snake_part_t *Snake::getBody() const
{
    return _body;
}

unsigned int Snake::getSize() const
{
    return _size;
}
