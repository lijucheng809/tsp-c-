//
// Created by 李炬成 on 2020/12/25.
//

#ifndef GLS__FLS_GLS_H
#define GLS__FLS_GLS_H
#include "../Points/Point.h"
#include<vector>
#include "../../cost/twoOptMoveCost.h"
class GLS {
private:
    int nCitys;
    double lambda;
    int maxRuns;
    double initDistance;
    double bestDistance;
    vector<Point>points;
    int **penaltysMatrix;
    void penalise();
public:
    GLS(int nCitys,double lambda,vector<Point>& points,int maxRuns,double initDist);
    inline ~GLS(){
        for(int i=0;i<nCitys;i++){
            delete []penaltysMatrix[i];
        }
        vector<Point>().swap(points);
    }

    void optimise();
    inline vector<Point>& bestSolution() {return points;}
    inline double optDistance()  {return bestDistance;}
};


#endif //GLS__FLS_GLS_H
