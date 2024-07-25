#pragma once
#include "empty.h"
#include "window.h"
#include "draw.h"
#include "fruit.h"
#include <cstddef>
#include <ctime>

class SnakeGame
{
public:
    SnakeGame(int height, int width) : fruit(nullptr)
    {
        pg = Playground(height, width);
        pg.init();
        game_over = false;
        srand(time(NULL));
    }

    ~SnakeGame()
    {
        delete fruit;
    }

    void handleInput()
    {
        chtype input = pg.getInput();
    }

    void updateState()
    {
        int y, x;
        pg.getEmptyCoordinates(y, x);

        pg.add(Drawable(10, 10, '@'));

        if(fruit != NULL)
        {
            pg.add(Empty(fruit->getY(), fruit->getX()));
            delete fruit;
            fruit = NULL;
        }

        fruit = new Fruit(y, x);
        pg.add(*fruit);
    }

    void redraw()
    {
        pg.refreshWin();
    }

    bool isOver()
    {
        return game_over;
    }

private:
    Playground pg;
    bool game_over;
    Fruit* fruit;
};
