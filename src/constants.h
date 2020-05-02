#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define PIN_CLK_MATRIX (5)
#define PIN_CS_MATRIX (6)
#define PIN_DIN_MATRIX (7)

#define INITIAL_SNAKE_SIZE (1)
#define INITIAL_SNAKE_X (0)
#define INITIAL_SNAKE_Y (0)

#define GRID_SIZE (8)

#define PIN_BUTTON_RIGHT (8)
#define PIN_BUTTON_UP (9)
#define PIN_BUTTON_DOWN (10)
#define PIN_BUTTON_LEFT (11)

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
} directions_e;

#endif // CONSTANTS_HPP
