//
// Created by 李炬成 on 2020/12/26.
//

#include "PointArray.h"
#include<fstream>
using namespace std;
vector<Point> & PointArray::genPointArray() {
    ifstream file(filename);
    if(!file){
        cout<<"Error opening file";
        return points;
    }
    for(int i=0;i<nCitys;i++){
        int id;
        file>>id;
        double xy[2];
        for(double & j : xy){
            file>>j;
        }
        Point point(id,xy[0],xy[1],true);
        points.push_back(point);
    }
    return points;
}