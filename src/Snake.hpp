#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "constants.h"

typedef struct {
    int x;
    int y;
} snake_part_t;

class Snake {
    public:
        Snake();
        void reset();
        void move();
        int getX() const;
        int getY() const;
        void setDirection(directions_e newDirection);
        void grow();

    private:
        snake_part_t  _body[GRID_SIZE * GRID_SIZE];
        unsigned int _size;
        directions_e _direction;
        int applyNextPos(snake_part_t *part);
};

#endif // SNAKE_HPP
