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
        int row;
        int col;
        int parent_row;
        int parent_col;
        int hScore = 0.0;
        double gScore = 0.0;
        double fScore = 0.0;
        int isObstacle = 0;
        int isBegin = 0;
        int isEnd = 0;
        int done = 0;

    public:
        cell(int a, int b);
        cell(const cell &c);
        ~cell();
        void set_parent(const cell &p);
        void set_gScore(cell father);
        void set_hScore(cell end);
        void set_fScore();
        void set_isObstacle();
        void set_isBegin();
        void set_isEnd();
        void set_done();
        int get_parent_row();
        int get_parent_col();
        int get_row();
        int get_col();
        int get_isObstacle();
        int get_isBegin();
        int get_isEnd();
        int get_done();
        int get_hScore();
        double get_gScore();
        double get_fScore();
    };
}



#endif //A_STAR_CELL_H
