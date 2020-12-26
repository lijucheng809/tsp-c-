//
// Created by 李炬成 on 2020/12/25.
//

#ifndef GLS__FLS_FLS_H
#define GLS__FLS_FLS_H
#include<iostream>
#include<vector>
#include "../Points/Point.h"
#include "../../cost/twoOptMoveCost.h"
using namespace std;

class FLS {
private:
    int nCitys;
    vector<Point>points;
    double findmove(int current);
    bool isBasic;
    double lambda;
    int **penaltysMatrix;
    double optDistance;

    inline int wrap(int i ,int max){ return (i+max)%max ;}
    inline void toActive(int a , int b ,int c , int d){
        points[a].setActive(true);
        points[b].setActive(true);
        points[c].setActive(true);
        points[d].setActive(true);
    }
    void reverse(int from , int to);
public:
    FLS(vector<Point>& points,int nCitys,bool isBasic,double distance,int **penaltysMatrix=NULL,double lambda=0);
    ~ FLS();
    vector<Point>& optimise();
    double tourDistance();
    inline double getoptDistance() const { return optDistance;}
};

#endif //GLS__FLS_FLS_H