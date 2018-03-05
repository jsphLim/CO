//
// Created by yue on 18-3-1.
//
#include "string"
#include "Map.h"
#include "iostream"
#include "fstream"
#include "cmath"

std::string DIMESION_PROPERTY = "DIMENSION";
std::string BEST_PROPERTY = "BEST";
std::string START_VERTEX_PAGE = "NODE_COORD_SECTION";

using namespace std;
double square(double x){
    return x*x;
};

double Map::getDistance(int v1, int v2) {
    double distance = sqrt(
            square( this->graph[v1][0] - this->graph[v2][0] )
            + square( this->graph[v1][1] - this->graph[v2][1] )  //graph[][] 图上的点和它的xy坐标
    );
    return distance;
}

Map::Map(string filePath){
    string line;
    cout << endl;
    ifstream dataFile;
    dataFile.open(filePath.c_str());
    if(dataFile.is_open()){
        bool vertexDataRegion = false;
        while(dataFile.good()){
            getline(dataFile,line);
            cout<<line<<endl;
            if(vertexDataRegion){
                int vertexId;
                double posX;
                double posY;
                sscanf(line.c_str(), "%d %lf %lf", &vertexId,&posX,&posY);
//                cout<<vertexId<<posX<<posY<<endl;
                vertexId--; // we store vertex from 0

                this->graph[vertexId][0] = posX;
                this->graph[vertexId][1] = posY;
            }

            if(line.find(DIMESION_PROPERTY) == 0){
                unsigned int index = 0;
                for(; index < line.size(); index++){
                    if ( line[index] >= '0' && line[index] <= '9') break;
                }
                this->vertexNum = atoi(line.substr(index,100).c_str());
                cout << "vertexNum : " << this->vertexNum << endl;

                this->graph = new double*[this->vertexNum];
                for(int i = 0; i < this->vertexNum; i++){
                    this->graph[i] = new double[2];
                }
            }

            if(line.find(BEST_PROPERTY) == 0){
                int bestValue;
                unsigned int index = 0;
                for(; index < line.size(); index++){
                    if ( line[index] >= '0' && line[index] <= '9') break;
                }
                bestValue = atoi(line.substr(index,100).c_str());
                cout << "bestValue: " << bestValue << endl;
            }

            if(line.find(START_VERTEX_PAGE) == 0){
                vertexDataRegion = true;
            }
        }
        dataFile.close();
        cout<<"end"<<endl;
    }
    else{
        cout<<"error"<<endl;
    }
}
