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
            if (_body[i].x == -1)
                _body[i].x = GRID_SIZE - 1;
            if (_body[i].x == GRID_SIZE)
                _body[i].x = 0;
            if (_body[i].y == -1)
                _body[i].y = GRID_SIZE - 1;
            if (_body[i].y == GRID_SIZE)
                _body[i].y = 0;
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
    if (newDirection == NONE)
        return;
    if ((newDirection == LEFT && _direction == RIGHT) ||
        (newDirection == RIGHT && _direction == LEFT) ||
        (newDirection == UP && _direction == DOWN) ||
        (newDirection == DOWN && _direction == UP))
        return;
        _direction = newDirection;
}

void Snake::grow()
{
    _size += 1;
}

bool Snake::eatsItself() const
{
    snake_part_t head = _body[0];

    for (unsigned int i = 1; i < _size; i++) {
        if (_body[i].x == head.x && _body[i].y == head.y)
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

bool Snake::isOnSnakeBody(int x, int y) const
{
    for (unsigned int i = 0; i < _size; i++) {
        if (x == _body[i].x && y == _body[i].y)
            return true;
    }
    return false;
}
