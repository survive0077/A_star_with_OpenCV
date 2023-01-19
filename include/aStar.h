//
// Created by yxj on 23-1-19.
//

#ifndef A_STAR_ASTAR_H
#define A_STAR_ASTAR_H
#include "../include/cell.h"
#include <iostream>
#include <vector>

namespace aStar
{
    bool aStar(std::vector <std::vector<cell::cell> > &map,
               std::vector<cell::cell> &openSet,
               std::vector<cell::cell> &closeSet,
               cell::cell beginCell, cell::cell endCell);
    bool cmp_f(cell::cell a, cell::cell b);
    std::vector<cell::cell> getNeighbors(std::vector <std::vector<cell::cell> > map,
                                         cell::cell currentCell);
}
#endif //A_STAR_ASTAR_H
