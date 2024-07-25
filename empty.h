#pragma once
#include <curses.h>
#include "draw.h"

class Empty : public Drawable
{

public:
    Empty(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->playerIcon = ' ';
    }
};
