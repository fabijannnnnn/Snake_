#pragma once
#include "draw.h"
#include "ncurses.h"
#include <queue>

enum Direction
{
    up,
    down,
    left,
    right,
};

class SnakePiece : public Drawable
{
public:

    SnakePiece()
    {
        this->y = this->x = 0;
        this->playerIcon = 'x';
    }

    SnakePiece(int y, int x)
    {
        this->x = x;
        this->y = y;
        this->playerIcon = '#';
    }
};

class Snake
{
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;

public:
    Snake()
    {
        cur_direction = up;
    }

    void addPiece(SnakePiece piece)
    {
        prev_pieces.push(piece);
    }

    void removePiece()
    {
        prev_pieces.pop();
    }

    SnakePiece head()
    {
        return prev_pieces.front();
    }

    SnakePiece tail()
    {
        return prev_pieces.back();
    }


    Direction getDirection()
    {
        return cur_direction;
    }

    void setDirection(Direction dir)
    {
        cur_direction = dir;
    }

    SnakePiece nextHead()
    {
        int row = head().getX();
        int col = head().getY();

        switch (cur_direction)
        {
            case down:
            row++;
            break;
            case up:
            row--;
            break;
            case left:
            col --;
            break;
            case right:
            col++;
            break;
        }

        return SnakePiece(row, col);
    }
};
