#include <curses.h>
#include <iostream>
#include "game.h"

#define PG_SIZE 20
#define PG_COLLUMNS PG_SIZE
#define PG_ROWS PG_SIZE * 2.5

int main(int argc, char ** argv)
{
    // Playground pg;

    initscr();
    refresh();

    noecho();

    SnakeGame game(PG_COLLUMNS, PG_ROWS);

    while (!game.isOver())
    {
        game.handleInput();

        game.updateState();

        game.redraw();
    }

    getch();
    endwin();

    std::cout << "hello there\n";
}
