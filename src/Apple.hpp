#ifndef APPLE_HPP
#define APPLE_HPP

#include "constants.h"

class Apple {
    public:
        Apple();
        void changePosition();
        int getX() const;
        int getY() const;

    private:
        int _x;
        int _y;
};

#endif // APPLE_HPP
