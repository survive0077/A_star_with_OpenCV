//
// Created by yxj on 23-1-18.
//
#include "../include/show.h"
#include "../include/cell.h"
#include <vector>
#include "opencv2/opencv.hpp"

namespace show
{
    void showMap(std::vector<std::vector<cell::cell> > map, cv::Mat &background)
    {
        int rowNum = (int)map.size();
        int columnNum = (int)map[0].size();
        int mapLength = columnNum * intervel;
        int mapHeight = rowNum * intervel;
        cv::Scalar color = cv::Scalar(100, 100, 100);
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
                if(map[r][c].get_done() == 1)
                {
                    cv::Rect rect = cv::Rect(c * intervel, r * intervel,
                                             intervel, intervel);
                    cv::rectangle(background, rect, cv::Scalar(255, 0, 0), 3, cv::LINE_8);
                }
                if(map[r][c].get_isBegin() == 1)
                {
                    cv::circle(background, cv::Point2f((c+0.5) * intervel, (r+0.5) * intervel),
                               intervel / 2, cv::Scalar(255, 255, 0), -1);
                }
                if(map[r][c].get_isEnd() == 1)
                {
                    cv::circle(background, cv::Point2f((c+0.5) * intervel, (r+0.5) * intervel),
                               intervel / 2, cv::Scalar(0, 0, 0), -1);
                }
            }
        }

        cv::namedWindow("map", 1);
        cv::imshow("map", background);
        cv::waitKey(10);
    }

    void showPath(std::vector<std::vector<cell::cell> > map, int endRow, int endColumn, cv::Mat &background)
    {
        std::vector<cell::cell> path;
        int parent_row = map[endRow - 1][endColumn - 1].get_parent_row();
        int parent_col = map[endRow - 1][endColumn - 1].get_parent_col();
        cv::circle(background, cv::Point2f((parent_col-0.5) * intervel, (parent_row-0.5) * intervel),
                   intervel / 4, cv::Scalar(0, 0, 255), -1);
        while(map[parent_row - 1][parent_col - 1].get_isBegin() == 0)
        {
            path.push_back(map[parent_row - 1][parent_col - 1]);
            int temp_row = map[parent_row - 1][parent_col - 1].get_parent_row();
            int temp_col = map[parent_row - 1][parent_col - 1].get_parent_col();
            parent_row = temp_row;
            parent_col = temp_col;

            cv::circle(background, cv::Point2f((parent_col-0.5) * intervel, (parent_row-0.5) * intervel),
                       intervel / 4, cv::Scalar(0, 0, 255), -1);
            cv::namedWindow("map", 1);
            cv::imshow("map", background);
            cv::waitKey(100);
        }
        path.push_back(map[parent_row - 1][parent_col - 1]);
        cv::destroyWindow("map");
    }

    void showResult(std::vector<std::vector<cell::cell> > map, cv::Mat background)
    {
        cv::namedWindow("result", 1);
        cv::imshow("result", background);
        cv::waitKey(0);
    }
}