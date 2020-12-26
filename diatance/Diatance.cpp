//
// Created by 李炬成 on 2020/12/26.
//

#include "Diatance.h"
double Diatance::genTourDistance() {
    double totalDis = 0;
    for(int i = 0;i<points.size()-1;i++){
        double dij = points[i].distance(points[i+1]);
        totalDis += dij;
    }
    totalDis = totalDis + points[points.size()-1].distance(points[0]);
    return totalDis;
}