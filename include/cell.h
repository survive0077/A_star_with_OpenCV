//
// Created by yxj on 23-1-18.
//

#ifndef A_STAR_CELL_H
#define A_STAR_CELL_H

namespace cell
{
    class cell
    {
    private:
        int x;
        int y;
        int hScore = 0.0;
        double gScore = 0.0;
        int isObstacle = 0;

    public:
        cell(int a, int b);
        ~cell();
        void set_gScore(cell father);
        void set_hScore(cell end);
        void set_isObstacle();
        int get_x();
        int get_y();
        double get_gScore();
        int get_hScore();
        int get_isObstacle();
    };
}



#endif //A_STAR_CELL_H
