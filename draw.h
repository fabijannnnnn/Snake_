#pragma once
#include <curses.h>

class Drawable
{
public:

    Drawable()
    {
        x = y = 0;
        playerIcon = ' ';
    }
    Drawable(int y, int x, chtype ch)
    {
        this->y = y;
        this->x = x;
        this->playerIcon = ch;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    chtype getIcon()
    {
        return playerIcon;
    }
protected:
    int y, x;
    chtype playerIcon;
};
