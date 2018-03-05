//
// Created by yue on 18-3-1.
//

#ifndef FORBIDENEDALGORITHM_TSP_H
#define FORBIDENEDALGORITHM_TSP_H

#include "Map.h"
#include "solution.h"

class TSP{
public:
    TSP(string file);
    solution* getBestNearby(int);
    void memsetTSP();
    void solve(int);

private:
    double bestScore;
    Map* map;
    solution* sol;
    int** tabu;
    int** tabu_f;
};

#endif //FORBIDENEDALGORITHM_TSP_H
