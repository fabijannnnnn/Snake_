#pragma once

#include <ncurses.h>
#include <curses.h>

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
    void addAt(int y, int x, chtype ch)
    {
        mvwaddch(pg_win, y, x, ch);
    }
    chtype getInput()
    {
        return wgetch(pg_win);
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

    void construct(int height, int width)
    {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        pg_win = newwin(height,width, (yMax/2)-(height/2), (xMax/2)-(width/2));

        addBorder();
    }
};
