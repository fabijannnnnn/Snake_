#pragma once
#include <curses.h>
#include "draw.h"

class Fruit : public Drawable
{

public:
    Fruit(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->playerIcon = 'F';
    }
};
