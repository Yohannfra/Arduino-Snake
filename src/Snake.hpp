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
        const snake_part_t *getBody() const;
        void setDirection(directions_e newDirection);
        void grow();
        bool eatsItself() const;
        unsigned int getSize() const;

    private:
        snake_part_t  _body[GRID_SIZE * GRID_SIZE];
        unsigned int _size;
        directions_e _direction;
};

#endif // SNAKE_HPP
