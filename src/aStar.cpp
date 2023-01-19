//
// Created by yxj on 23-1-19.
//
#include "../include/aStar.h"
#include "../include/cell.h"
#include <algorithm>

namespace aStar
{
    bool aStar(std::vector<std::vector<cell::cell>> &map,
               std::vector<cell::cell> &openSet,
               std::vector<cell::cell> &closeSet,
               cell::cell beginCell, cell::cell endCell)
    {
        bool ifFinish = false;
        if(! openSet.empty())
        {
            std::sort(openSet.begin(), openSet.end(), cmp_f);
            cell::cell currentCell(openSet.back());
            openSet.pop_back();
            closeSet.push_back(currentCell);
            map[currentCell.get_row() - 1][currentCell.get_col() - 1].set_done();
            if(currentCell.get_isEnd() == 1)
            {
                ifFinish = true;
                std::cout<<"Finish!";
            }
            else
            {
                std::vector<cell::cell> neighbors;
                neighbors = getNeighbors(map, currentCell);
                for(auto n : neighbors)
                {
                    if(n.get_isObstacle() != 1 && n.get_done() != 1)
                    {
                        n.set_gScore(currentCell);
                        n.set_hScore(endCell);
                        n.set_fScore();
                        map[n.get_row() - 1][n.get_col() - 1].set_parent(currentCell);
                        n.set_parent(currentCell);
                        openSet.push_back(n);
                    }
                }
            }
        }
        else
        {
            if(closeSet.empty())
            {
                cell::cell currentCell(beginCell);
                closeSet.push_back(currentCell);
                map[currentCell.get_row() - 1][currentCell.get_col() - 1].set_done();
                std::vector<cell::cell> neighbors;
                neighbors = getNeighbors(map, currentCell);
                for(auto n : neighbors)
                {
                    if(n.get_isObstacle() != 1 && n.get_done() != 1)
                    {
                        n.set_gScore(currentCell);
                        n.set_hScore(endCell);
                        n.set_fScore();
                        n.set_parent(currentCell);
                        map[n.get_row() - 1][n.get_col() - 1].set_parent(currentCell);
                        openSet.push_back(n);
                    }
                }
            }
            else
            {
                ifFinish = true;
                std::cout<<"No way!";
            }
        }

        return ifFinish;
    }

    bool cmp_f(cell::cell a, cell::cell b)
    {
        return  a.get_fScore() > b.get_fScore();
    }

    std::vector<cell::cell> getNeighbors(std::vector <std::vector<cell::cell> > map,
                                         cell::cell currentCell)
    {
        int thisCol = currentCell.get_col() - 1;
        int thisRow = currentCell.get_row() - 1;
        int up = thisRow - 1;
        int down = thisRow + 1;
        int right = thisCol + 1;
        int left = thisCol - 1;
        std::vector<cell::cell> neighbors;
        if(left >= 0)
            neighbors.push_back(map[thisRow][left]);
        if(right <= (int)map[thisRow].size() - 1)
            neighbors.push_back(map[thisRow][right]);
        if(up >= 0 && thisCol <= (int)map[up].size() - 1)
            neighbors.push_back(map[up][thisCol]);
        if(down <= (int)map.size() - 1 && thisCol <= (int)map[down].size() - 1)
            neighbors.push_back(map[down][thisCol]);
        if(left >= 0 && up >= 0 && left <= (int)map[up].size() - 1)
            neighbors.push_back(map[up][left]);
        if(up >= 0 && right <= (int)map[up].size() - 1)
            neighbors.push_back(map[up][right]);
        if(left >= 0 && down <= (int)map.size() - 1 && left <= (int)map[down].size() - 1)
            neighbors.push_back(map[down][left]);
        if(down <= (int)map.size() - 1 && right <= (int)map[down].size() - 1)
            neighbors.push_back(map[down][right]);

        return neighbors;
    }
}