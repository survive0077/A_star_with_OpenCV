//
// Created by yxj on 23-1-18.
//
#include "../include/show.h"
#include "../include/cell.h"
#include <vector>
#include "opencv2/opencv.hpp"

namespace show
{
    void showMap(std::vector<std::vector<cell::cell>> map, cv::Mat background)
    {
        int rowNum = (int)map.size();
        int columnNum = (int)map[0].size();
        int mapLength = columnNum * intervel;
        int mapHeight = rowNum * intervel;
        cv::Scalar color = cv::Scalar(0, 0, 255);
        for(int i = 0; i <= rowNum; i++)
        {
            cv::Point2i begin(0, i * intervel);
            cv::Point2i end(mapLength, i * intervel);
            cv::line(background, begin, end, color, 1, cv::LINE_8);
        }
        for(int j = 0; j <= columnNum; j++)
        {
            cv::Point2i begin(j * intervel, 0);
            cv::Point2i end(j * intervel, mapHeight);
            cv::line(background, begin, end, color, 1, cv::LINE_8);
        }
        for(int r = 0; r < rowNum; r++)
        {
            for(int c = 0; c < columnNum; c++)
            {
                if(map[r][c].get_isObstacle() == 1)
                {
                    cv::Rect rect = cv::Rect(c * intervel, r * intervel,
                                                  intervel, intervel);
                    cv::rectangle(background, rect, color, -1, cv::LINE_8);
                }
            }
        }

        cv::namedWindow("map", 1);
        cv::imshow("map", background);
        cv::waitKey(0);
    }
}