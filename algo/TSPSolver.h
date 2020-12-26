//
// Created by 李炬成 on 2020/12/26.
//

#ifndef GLS__FLS_TSPSOLVER_H
#define GLS__FLS_TSPSOLVER_H
#include<string>
#include<vector>
#include "../algo/Points/Point.h"
#include "../data/PointArray.h"
#include "../algo/FLS/FLS.h"
#include "../algo/GLS/GLS.h"
using namespace std;

class TSPSolver {
private:
    int nCitys;
    string filename;
    vector<Point>points;
    //FLS *fls;
public:
    TSPSolver(int nCitys,string filename):nCitys(nCitys),filename(filename){
        PointArray readfile(nCitys,filename);
        points = readfile.genPointArray();
    }
    ~TSPSolver(){};
    FLS FLS_solver();
    GLS GLS_FLS_solver(double alph,int maxRuns);

};


#endif //GLS__FLS_TSPSOLVER_H
