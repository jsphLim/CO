//
// Created by yue on 18-3-1.
//

#ifndef FORBIDENEDALGORITHM_SOLUTION_H
#define FORBIDENEDALGORITHM_SOLUTION_H

#include "Map.h"
#include "iostream"

using namespace std;

class solution{
private:
    Map* map;
    double score;
    int* v;
public:

    solution(Map *map);
    void init();
    void compute();
    double getScore();
    void setV(int key,int value);
    int getV(int key);
    void outputPath();
    void swap_solve(int,int);

};


#endif //FORBIDENEDALGORITHM_SOLUTION_H
