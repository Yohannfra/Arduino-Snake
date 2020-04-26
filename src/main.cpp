#include <Arduino.h>
#include <time.h>
#include "Game.hpp"

void setup()
{
    srand(time(NULL));
    Game g;
    g.start();
}

void loop()
{
}
