//
// Created by yue on 18-3-1.
//

#include "solution.h"
#include "time.h"
#include "iostream"

using namespace std;

solution::solution(Map *map) {
    this->map=map;
    score=0;
    v=new int[map->vertexNum];
    init();
}

void solution::init() {
    for(int i=0;i<map->vertexNum;i++) this->v[i]=i;
    srand(time(NULL));
    for(int i=(map->vertexNum-1);i>=0;i--){
        int temp = rand()%map->vertexNum;
        swap(this->v[i],this->v[temp]);
    }
    compute();
}


void solution::compute() {
    score=0;
    for(int i=0;i<(map->vertexNum-1);i++) score+=map->getDistance(this->v[i],this->v[i+1]);
    score+=map->getDistance(this->v[map->vertexNum-1],this->v[0]);
}

void solution::outputPath() {
    cout<<"the path is:  ";
    for(int i = 0; i < map->vertexNum; i++){
        cout << this->v[i] << " ";
    }
    cout << endl;
}

void solution::swap_solve(int i, int j) {
    swap(this->v[i],this->v[j]);
}

double solution::getScore() { compute(); return score;}
int solution::getV(int key) {return this->v[key];}
void solution::setV(int key, int value) {this->v[key]=value;}

