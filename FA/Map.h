//
// Created by yue on 18-3-1.
//

#ifndef FORBIDENEDALGORITHM_MAP_H
#define FORBIDENEDALGORITHM_MAP_H
#include<string>
using namespace std;

class Map{
public:
    int vertexNum;
    string file;
    double** graph;
    Map(string file);
    double getDistance(int,int);
};
#endif //FORBIDENEDALGORITHM_MAP_H
