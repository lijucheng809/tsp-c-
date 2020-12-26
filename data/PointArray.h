//
// Created by 李炬成 on 2020/12/26.
//

#ifndef GLS__FLS_POINTARRAY_H
#define GLS__FLS_POINTARRAY_H
#include<string>
#include<vector>
using namespace std;
#include "../algo/Points/Point.h"
class PointArray {
private:
    string filename;
    int nCitys;
    vector<Point>points;
public:
    PointArray(int nCitys,string filename):nCitys(nCitys),filename(filename){}
    ~PointArray(){}
    vector<Point>& genPointArray();
};


#endif //GLS__FLS_POINTARRAY_H
