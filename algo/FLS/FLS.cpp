//
// Created by 李炬成 on 2020/12/25.
//
#include "FLS.h"

FLS::FLS(vector<Point>& points,int nCitys,bool isBasic,double distance,int **penaltysMatrix,double lambda) :
points(points),nCitys(nCitys),isBasic(isBasic),optDistance(distance),lambda(lambda),penaltysMatrix(penaltysMatrix){
}
FLS::~ FLS(){
    vector<Point>().swap(points);
}
void FLS::reverse(int from, int to) {
    for(int i = from , j = to;i<j;i++,j--){
        swap(points[i],points[j]);
    }
}
double FLS::findmove(int current) {
    int pre = wrap(current-1,nCitys);
    int next = wrap(current+1,nCitys);
    for(int i = wrap(current+2,nCitys),j = wrap(current+3,nCitys);j!=current && j!=pre;i=j,j=wrap(j+1,nCitys)){
        twoOptMoveCost twoopt1(isBasic,pre,current,i,j);
        double delt1 = twoopt1.moveCost(points,penaltysMatrix,lambda);
        if(delt1 < 0 ){

            toActive(pre,current,i,j);
            reverse(min(pre,i)+1,max(pre,i));
            return delt1;
        }
        twoOptMoveCost twoopt2(isBasic,current,next,i,j);
        double delt2 = twoopt2.moveCost(points,penaltysMatrix,lambda);
        if(delt2 < 0 ){
            toActive(current,next,i,j);
            reverse(min(current,i)+1,max(current,i));
            return delt2;
        }
    }
    return 1;
}
double FLS::tourDistance() {
    double totalDis = 0;
    for(int i = 0;i<points.size()-1;i++){
        double dij = points[i].distance(points[i+1]);
        totalDis += dij;
    }
    totalDis = totalDis + points[points.size()-1].distance(points[0]);
    return totalDis;
}
vector<Point>& FLS::optimise() {
    int visted = 0, current = 0;
    while(visted < nCitys){
        if(points[current].isActive()){
            double modified = findmove(current);
            if(modified < 0){
                current = wrap(current-1,nCitys);
                visted = 0;
                optDistance += modified;
                continue;
            }
            points[current].setActive(false);
        }
        current = wrap(current+1,nCitys);
        visted++;
    }
    return points;
}