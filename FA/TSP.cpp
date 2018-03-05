//
// Created by yue on 18-3-2.
//

#include <limits>
#include <utility>
#include "TSP.h"
#include "string"
#include "iostream"

using namespace std;

#define TABU_LENGTH 30
#define NUM_INTERATION 3000
#define PENAL_LONG_TERM 10
#define LONG_TERM_LENGTH 100
#define TIME_TRY 500

TSP::TSP(string file) {
    map = new Map(file);

    sol = new solution(map);
    bestScore = std::numeric_limits<double >::max();

    tabu = new int* [map->vertexNum];
    tabu_f = new int* [map->vertexNum];
    for(int i=0;i<map->vertexNum;i++){
        tabu[i] = new int[map->vertexNum];
        tabu_f[i] = new int[map->vertexNum];
    }
    memsetTSP();

}

void TSP::memsetTSP() {
    for(int i=0;i<map->vertexNum;i++)
        for(int j=0;j<map->vertexNum;j++){
            tabu_f[i][j]=0;
            tabu[i][j]=0;
        }
}


void TSP::solve(int numCandidate){
    solution bestSolution(map);
    double bestSolutionScore = bestSolution.getScore();

    for(int loopCount = 0; loopCount < numCandidate; loopCount++){
        sol->init();
        memsetTSP();
        //cout << "Init Score : " << s->getScore() << endl;
        int countTime = 0;
        bestScore = std::numeric_limits<double>::max();
        for(int i = 0; i < NUM_INTERATION; i++){
            sol = this->getBestNearby(i);
            double score = sol->getScore();
            if(score < bestScore){
                bestScore = score;
                countTime = 0;

                if(bestScore < bestSolutionScore){
                    for(int j = 0; j < map->vertexNum; j++){
                        bestSolution.setV(j,sol->getV(j));
                    }
                    bestSolutionScore = bestScore;
                }
            }else{
                countTime++;
                if(countTime > TIME_TRY){
                    break;
                }
            }
        }

    }
    cout << "Best score : " << bestSolutionScore << endl;
    bestSolution.outputPath();
}








solution* TSP::getBestNearby(int t) {
    double bestscore = std::numeric_limits<double >::max();
    int v1=0;
    int v2=1;
    for(int i=0;i<map->vertexNum;i++){
        for(int j=i+1;j<map->vertexNum;j++){
            sol->swap_solve(i,j);
            double currentScore = sol->getScore();
            double penalScore = currentScore+tabu_f[i][j]*PENAL_LONG_TERM;
            if(((bestscore>penalScore)&&(this->tabu[i][j]<=t))||(currentScore<bestScore)){
                v1=i;
                v2=j;
                bestscore=penalScore;
                this->tabu[i][j]=(t+TABU_LENGTH);
                this->tabu[j][i]=(t+TABU_LENGTH);
            }

            sol->swap_solve(j,i);
            if(tabu_f[i][j]>0&&t<LONG_TERM_LENGTH) tabu_f[i][j]-=1;
        }
    }
    tabu_f[v1][v2]+=2;
    sol->swap_solve(v1,v2);
    return sol;
}
