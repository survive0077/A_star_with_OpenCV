//
// Created by yxj on 23-1-18.
//

#ifndef A_STAR_DOMAP_H
#define A_STAR_DOMAP_H

#include <vector>
#include <string>
#include "../include/cell.h"

namespace doMap
{
    std::vector<cell::cell> readLine(std::string line, int rowNum);
    std::vector<std::vector<cell::cell> > getMap(std::string file);
}

#endif //A_STAR_DOMAP_H
