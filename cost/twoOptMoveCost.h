//
// Created by 李炬成 on 2020/12/25.
//

#ifndef GLS__FLS_TWOOPTMOVECOST_H
#define GLS__FLS_TWOOPTMOVECOST_H
#include "../algo/Points/Point.h"
#include<vector>
using namespace std;
class twoOptMoveCost {
private:
    bool basicMove;
    int a_idx,b_idx,c_idx,d_idx;
    double basicTwoOptMoveCost(vector<Point>& points);
    double GLSTwoOptMoveCost(vector<Point>& points,int **penaltysMatrix,double lambda);


public:
    twoOptMoveCost(bool basicMove,int a_idx,int b_idx,int c_idx,int d_idx);
    double moveCost(vector<Point>& points,int **penaltysMatrix=NULL,double lambda=0);
    ~twoOptMoveCost(){};

};


#endif //GLS__FLS_TWOOPTMOVECOST_H
