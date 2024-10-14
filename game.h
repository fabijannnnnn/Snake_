#pragma once
#include "empty.h"
#include "window.h"
#include "draw.h"
#include "fruit.h"
#include <cstddef>
#include <ctime>
#include "snake.h"

class SnakeGame
{
    Playground pg;
    bool game_over;
    Fruit* fruit;
public:

    // SnakeGame(int height, int width) : fruit(nullptr)
    // {
    //     pg = Playground(height, width);
    // }

    SnakeGame(int height, int width)
    {
        pg = Playground(height, width);
        initialize();
    }

    ~SnakeGame()
    {
        delete fruit;
    }

    void initialize()
    {
        pg.init();
        game_over = false;
        srand(time(NULL));
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

        if(fruit != nullptr)
        {
            pg.add(Empty(fruit->getY(), fruit->getX()));
            delete fruit;
            fruit = nullptr;
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

};
