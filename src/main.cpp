//
// Created by yxj on 23-1-18.
//
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include "../include/cell.h"
#include "../include/doMap.h"
#include "../include/show.h"
#include "../include/aStar.h"


int main(int argc, char* argv[])
{
    std::string filePath = "../../map.board";
    std::vector <std::vector<cell::cell> > map;
    map = doMap::getMap(filePath);
    cv::Mat background(640, 640, CV_8UC3, cv::Scalar(255, 255, 255));

    int beginRow = 2;
    int beginColumn = 2;
    int endRow = 2;
    int endColumn = 16;
    map[beginRow - 1][beginColumn - 1].set_isBegin();
    map[endRow - 1][endColumn - 1].set_isEnd();
    cell::cell beginCell(map[beginRow - 1][beginColumn - 1]);
    cell::cell endCell(map[endRow - 1][endColumn - 1]);

    std::vector<cell::cell> openSet;
    std::vector<cell::cell> closeSet;
    while(! aStar::aStar(map, openSet, closeSet, beginCell, endCell))
    {
        show::showMap(map, background);
    }
    //std::vector<cell::cell> path = show::showPath(map, endCell, background);
    /*
     * 2 21
     * 3 20
     * 4 19
     * 5 18
     */

    show::showPath(map, endRow, endColumn, background);
    show::showResult(map, background);
    return 0;
}