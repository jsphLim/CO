#include <iostream>
#include "fstream"
#include "TSP.h"
#include "Map.h"
using namespace std;
int main() {
    TSP solver2("test3.txt");
    solver2.solve(6);

}
