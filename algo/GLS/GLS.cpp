//
// Created by 李炬成 on 2020/12/25.
//

#include "GLS.h"
#include "../FLS/FLS.h"
GLS::GLS(int nCitys, double lambda, vector<Point> &points, int maxRuns,double initDis) :
nCitys(nCitys),lambda(lambda),points(points),maxRuns(maxRuns),initDistance(initDis),bestDistance(initDis){
    penaltysMatrix = new int*[nCitys];
    for(int i=0;i<nCitys;i++){
        penaltysMatrix[i] = new int[nCitys];
    }
    for(int i=0;i<nCitys;i++)
        for (int j = 0; j < nCitys; ++j) {
            penaltysMatrix[i][j]=0;
        }
}
void GLS::penalise() {
    double maxUtil = 0;
    vector<Point>maxUtilFeatures;
    vector<int>pointsIndex;
    for(int i=0,j=1;i<points.size();i++,j=(j+1)%points.size()){
        double util = points[i].distance(points[j])/(penaltysMatrix[points[i].getId()][points[j].getId()]+1);
        if(util > maxUtil){
            vector<Point>().swap(maxUtilFeatures);
            vector<int>().swap(pointsIndex);
            maxUtilFeatures.push_back(points[i]);
            maxUtilFeatures.push_back(points[j]);
            pointsIndex.push_back(i);
            pointsIndex.push_back(j);
            maxUtil = util;
        }else if(util == maxUtil){
            maxUtilFeatures.push_back(points[i]);
            maxUtilFeatures.push_back(points[j]);
            pointsIndex.push_back(i);
            pointsIndex.push_back(j);
        }
    }
    for(int i=0;i<maxUtilFeatures.size();i+=2){
        penaltysMatrix[maxUtilFeatures[i].getId()][maxUtilFeatures[i+1].getId()] += 1;
        penaltysMatrix[maxUtilFeatures[i+1].getId()][maxUtilFeatures[i].getId()] += 1;
        points[pointsIndex[i]].setActive(true);
        points[pointsIndex[i+1]].setActive(true);
    }
}
void GLS::optimise() {
    for(int i= 0;i<maxRuns;i++){
        penalise();
        FLS localsearch(points,nCitys,false,bestDistance,penaltysMatrix,lambda);
        vector<Point>temp = localsearch.optimise();
        double realDistance = localsearch.tourDistance();
        if(realDistance<bestDistance){
            vector<Point>copy;
            copy.assign(temp.begin(),temp.end());
            points.assign(copy.begin(),copy.end());
            bestDistance = realDistance;
        }
    }
    cout<<"the optSolution has been solved"<<endl;
}