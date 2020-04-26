#include "Snake.hpp"

Snake::Snake()
{

}

void Snake::reset()
{
    _body[0].x = INITIAL_SNAKE_X;
    _body[0].y = INITIAL_SNAKE_Y;
    _size = INITIAL_SNAKE_SIZE;
    _direction = RIGHT;
}

int Snake::applyNextPos(snake_part_t *part)
{
    return 9;
}

void Snake::move()
{
    directions_e lastNodeDirection = NONE;

    for (int i = 0; i < _size; i++) {
        if (lastNodeDirection == NONE) { // snake head
            _body[i].x += 1;

        }


        /* switch (_direction) { */
        /*     case RIGHT: */
        /*         _head.x += 1; */
        /*         break; */
        /*     case LEFT: */
        /*         _head.x -= 1; */
        /*         break; */
        /*     case UP: */
        /*         _head.y -= 1; */
        /*         break; */
        /*     case DOWN: */
        /*         _head.y += 1; */
        /*         break; */
        /*     default: */
        /*         break; */
        /* } */
    }
}

int Snake::getX() const
{
    return _body[0].x;
}

int Snake::getY() const
{
    return _body[0].y;
}

void Snake::setDirection(directions_e newDirection)
{
    if (newDirection != NONE)
        _direction = newDirection;
}

void Snake::grow()
{
    // TODO
}
