//
// Created by 李炬成 on 2020/12/26.
//

#include "TSPSolver.h"
#include "../algo/FLS/FLS.h"
#include "../diatance/Diatance.h"

FLS TSPSolver::FLS_solver() {

    Diatance dis(points);
    double initdistance = dis.genTourDistance();
    FLS fls(points,nCitys,true,initdistance);

    return fls;

}

GLS TSPSolver::GLS_FLS_solver(double alph,int maxRuns) {

    FLS fls = FLS_solver();
    vector<Point> initsolution = fls.optimise();

    double initDistance = fls.getoptDistance();

    vector<Point>().swap(points);

    double lambda = alph*(initDistance/initsolution.size());

    GLS gls(nCitys,lambda,initsolution,maxRuns,initDistance);

    return gls;
}