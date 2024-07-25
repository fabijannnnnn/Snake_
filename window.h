#pragma once
#include "draw.h"
#include <cstdlib>

class Playground
{

public:
    Playground()
    {
        construct(0, 0);
    }

    Playground(int height, int width)
    {
        construct(height, width);
    }

    void init()
    {
        clear();
        refresh();
    }

    void addBorder()
    {
        box(pg_win, 0, 0);
    }

    void add(Drawable drawable)
    {
        addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
    }

    void addAt(int y, int x, chtype ch)
    {
        mvwaddch(pg_win, y, x, ch);
    }

    chtype getInput()
    {
        return wgetch(pg_win);
    }

    void getEmptyCoordinates(int &y, int &x)
    {
        y = rand() % height;
        x = rand() % width;

        while(mvwinch(pg_win, y, x) != ' ')
            ;
    }

    void clearWin()
    {
        wclear(pg_win);
        addBorder();
    }

    void refreshWin()
    {
        wrefresh(pg_win);
    }

    // ~Playground(){
    //     endwin();
    // }

private:
    WINDOW * pg_win;
    int height, width;

    void construct(int height, int width)
    {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        this->height = height;
        this->width = width;

        pg_win = newwin(height,width, (yMax/2)-(height/2), (xMax/2)-(width/2));

        addBorder();
    }
};
