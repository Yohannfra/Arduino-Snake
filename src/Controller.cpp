#include "Controller.hpp"
#include "constants.h"
#include <Arduino.h>

Controller::Controller()
{
    pinMode(PIN_BUTTON_UP, INPUT);
    pinMode(PIN_BUTTON_DOWN, INPUT);
    pinMode(PIN_BUTTON_LEFT, INPUT);
    pinMode(PIN_BUTTON_RIGHT, INPUT);
}

directions_e Controller::getEvent()
{
    if (digitalRead(PIN_BUTTON_UP))
        return UP;
    if (digitalRead(PIN_BUTTON_DOWN))
        return DOWN;
    if (digitalRead(PIN_BUTTON_LEFT))
        return LEFT;
    if (digitalRead(PIN_BUTTON_RIGHT))
        return RIGHT;
    return NONE;
}
