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
    int intervel = 50;
    void showMap(std::vector <std::vector<cell::cell>> map, cv::Mat background);
}
#endif //A_STAR_SHOW_H
