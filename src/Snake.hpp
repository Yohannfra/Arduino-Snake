#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "constants.h"

class Snake {
    public:
        Snake();
        void reset();

    private:
        int _headX;
        int _headY;
        unsigned int _size;
        directions_e _direction;
};

#endif // SNAKE_HPP
