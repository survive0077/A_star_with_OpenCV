//
// Created by yxj on 23-1-18.
//
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include "../include/cell.h"
#include "../include/doMap.h"
#include "../include/show.h"


int main(int argc, char* argv[])
{
    std::string filePath = "../map.board";
    std::vector <std::vector<cell::cell> > map;
    map = doMap::getMap(filePath);
    cv::Mat background(640, 640, CV_8UC3, cv::Scalar(255, 255, 255));
    show::showMap(map, background);
    return 0;
}