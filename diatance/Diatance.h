//
// Created by 李炬成 on 2020/12/26.
//

#ifndef GLS__FLS_DIATANCE_H
#define GLS__FLS_DIATANCE_H
#include "../algo/Points/Point.h"
#include<vector>
using namespace std;
class Diatance {
private:
    double distance;
    vector<Point>points;
public:
    Diatance(const vector<Point>& points):points(points){}
    ~Diatance(){};
    double genTourDistance();
};


#endif //GLS__FLS_DIATANCE_H
