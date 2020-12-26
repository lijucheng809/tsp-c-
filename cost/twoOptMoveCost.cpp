//
// Created by 李炬成 on 2020/12/25.
//
#include "twoOptMoveCost.h"
#include "../algo/Points/Point.h"
twoOptMoveCost::twoOptMoveCost(bool basicMove, int a_idx, int b_idx, int c_idx, int d_idx)
        :basicMove(basicMove),a_idx(a_idx),b_idx(b_idx),c_idx(c_idx),d_idx(d_idx){
}

double twoOptMoveCost::basicTwoOptMoveCost(vector<Point>& points) {
    double _ab = points[a_idx].distance(points[b_idx]);
    double _cd = points[c_idx].distance(points[d_idx]);
    double _ac = points[a_idx].distance(points[c_idx]);
    double _bd = points[b_idx].distance(points[d_idx]);
    if(_ab<_ac && _cd<_bd) return 1;
    return _ac+_bd-_ab-_cd;
}
double twoOptMoveCost::GLSTwoOptMoveCost(vector<Point> &points,int **penaltysMatrix,double lambda) {
    if(basicTwoOptMoveCost(points)==1) return 1;
    else{
        double deltD = basicTwoOptMoveCost(points);
        int _ab_p = penaltysMatrix[points[a_idx].getId()][points[b_idx].getId()];
        int _cd_p = penaltysMatrix[points[c_idx].getId()][points[d_idx].getId()];
        int _ac_p = penaltysMatrix[points[a_idx].getId()][points[c_idx].getId()];
        int _bd_p = penaltysMatrix[points[b_idx].getId()][points[d_idx].getId()];
        double deltP = (_ac_p + _bd_p - _ab_p - _cd_p)*lambda;
        return deltD + deltP;
    }
}

double twoOptMoveCost::moveCost(vector<Point>& points,int **penaltysMatrix,double lambda) {
    if(basicMove)
        return basicTwoOptMoveCost(points);
    else
        return GLSTwoOptMoveCost(points,penaltysMatrix,lambda);
}