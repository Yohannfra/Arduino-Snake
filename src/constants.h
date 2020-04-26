#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define PIN_CLK_MATRIX (8)
#define PIN_CS_MATRIX (9)
#define PIN_DIN_MATRIX (10)

#define INITIAL_SNAKE_SIZE (1)
#define INITIAL_SNAKE_X (0)
#define INITIAL_SNAKE_Y (0)

#define GRID_SIZE (8)

#define PIN_BUTTON_UP (1)
#define PIN_BUTTON_DOWN (2)
#define PIN_BUTTON_LEFT (3)
#define PIN_BUTTON_RIGHT (4)

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
} directions_e;

#endif // CONSTANTS_HPP
