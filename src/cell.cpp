//
// Created by yxj on 23-1-18.
//

#include "../include/cell.h"
#include <cmath>
namespace cell
{
    cell::cell(int a, int b)
    {
        x = a;
        y = b;
    }

    cell::~cell() {}

    void cell::set_gScore(cell father)
    {
        double add;
        add = sqrt(pow((father.get_x() - x), 2) + pow((father.get_y() - y), 2));
        gScore = father.get_gScore() + add;
    }

    void cell::set_hScore(cell end)
    {
        hScore = abs(end.get_x() - x) + abs(end.get_y() - y);
    }

    void cell::set_isObstacle()
    {
        isObstacle = 1;
    }

    int  cell::get_x()
    {
        return x;
    }

    int  cell::get_y()
    {
        return y;
    }

    double cell::get_gScore()
    {
        return gScore;
    }

    int  cell::get_hScore()
    {
        return hScore;
    }

    int cell::get_isObstacle()
    {
        return isObstacle;
    }
}

