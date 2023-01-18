//
// Created by yxj on 23-1-18.
//
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/cell.h"
#include "../include/doMap.h"
#include <iostream>

namespace doMap
{
    std::vector <cell::cell> readLine(std::string line, int rowNum)
    {
        std::vector<cell::cell> mapRow;
        std::istringstream sline(line);
        int num;
        int columnNum = 1;
        while (sline >> num)
        {
            cell::cell mapCell(rowNum, columnNum);
            if(num != 0)
                mapCell.set_isObstacle();
            mapRow.push_back(mapCell);
            columnNum += 1;
        }
        return mapRow;
    }

    std::vector <std::vector<cell::cell> > getMap(std::string file)
    {
        std::ifstream myFile(file);
        std::vector <std::vector<cell::cell> > map;
        if(myFile)
        {
            std::string row;
            int rowNum = 1;
            while (getline(myFile, row))
            {
                std::vector<cell::cell> mapRow = doMap::readLine(row, rowNum);
                map.push_back(mapRow);
                rowNum += 1;
            }
        }

        return map;
    }
}