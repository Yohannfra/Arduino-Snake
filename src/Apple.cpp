#include "Apple.hpp"
#include <stdlib.h>

Apple::Apple()
{
    changePosition();
}

void Apple::changePosition()
{
    _x = rand() % (GRID_SIZE);
    _y = rand() % (GRID_SIZE);
}

int Apple::getX() const
{
    return _x;
}

int Apple::getY() const
{
    return _y;
}
