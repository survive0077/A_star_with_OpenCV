//
// Created by yxj on 23-1-18.
//

#ifndef A_STAR_SHOW_H
#define A_STAR_SHOW_H
#include <vector>
#include "../include/cell.h"
#include "opencv2/opencv.hpp"

namespace show
{
    int intervel = 20;
    void showMap(std::vector <std::vector<cell::cell>> map, cv::Mat &background);
    void showPath(std::vector <std::vector<cell::cell>> map, int endRow, int endColumn, cv::Mat &background);
    void showResult(std::vector <std::vector<cell::cell>> map, cv::Mat background);
}
#endif //A_STAR_SHOW_H
