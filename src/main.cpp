#include <time.h>
#include "Game.hpp"
#include <Arduino.h>

void setup()
{
    srand(time(NULL));
    Game g;
    g.start();
}

void loop()
{
}
