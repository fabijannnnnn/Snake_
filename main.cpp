#include <curses.h>
#include <iostream>
#include "window.h"

#define PG_SIZE 20
#define PG_COLLUMNS PG_SIZE
#define PG_ROWS PG_SIZE * 2.5

int main(int argc, char ** argv)
{
    // Playground pg;

    initscr();
    refresh();

    Playground pg(PG_COLLUMNS, PG_ROWS);
    pg.init();

    pg.addAt(10, 10, 'O');

    pg.refreshWin();

    getch();
    endwin();

    std::cout << "hello there\n";
}
