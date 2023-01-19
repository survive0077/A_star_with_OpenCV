//
// Created by yxj on 23-1-18.
//

#include "../include/cell.h"
#include <cmath>
#include <algorithm>

namespace cell
{
    cell::cell(int a, int b)
    {
        row = a;
        col = b;
    }

    cell::cell(const cell &c)
    {
        row = c.row;
        col = c.col;
        parent_row = c.parent_row;
        parent_col = c.parent_col;
        hScore = c.hScore;
        fScore = c.fScore;
        hScore = c.hScore;
        isObstacle = c.isObstacle;
        isBegin = c.isBegin;
        isEnd = c.isEnd;
        done = c.done;
    }

    cell::~cell() {}

    void cell::set_parent(const cell &p)
    {
        parent_row = p.row;
        parent_col = p.col;
    }

    void cell::set_gScore(cell father)
    {
        double add;
        add = sqrt(pow((father.get_row() - row), 2) + pow((father.get_col() - col), 2));
        gScore = father.get_gScore() + add;
    }

    void cell::set_hScore(cell end)
    {
        int dy = abs(end.get_row() - row);
        int dx = abs(end.get_col() - col);
        hScore = (dx + dy) + (sqrt(2) - 2) * std::min(dx, dy);
    }

    void cell::set_fScore()
    {
        fScore = gScore + hScore;
    }

    void cell::set_isObstacle()
    {
        isObstacle = 1;
    }

    void cell::set_isBegin()
    {
        isBegin = 1;
    }

    void cell::set_isEnd()
    {
        isEnd = 1;
    }

    void cell::set_done()
    {
        done = 1;
    }

    int cell::get_parent_row()
    {
        return parent_row;
    }

    int cell::get_parent_col()
    {
        return parent_col;
    }

    int  cell::get_row()
    {
        return row;
    }

    int  cell::get_col()
    {
        return col;
    }

    int cell::get_isObstacle()
    {
        return isObstacle;
    }

    int cell::get_isBegin()
    {
        return isBegin;
    }

    int cell::get_isEnd()
    {
        return isEnd;
    }

    int cell::get_done()
    {
        return done;
    }

    int  cell::get_hScore()
    {
        return hScore;
    }

    double cell::get_gScore()
    {
        return gScore;
    }

    double cell::get_fScore()
    {
        return fScore;
    }
}

