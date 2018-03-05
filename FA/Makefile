all: tsp

tsp: solution.o Map.o TSP.o main.o
			g++ solution.o main.o Map.o TSP.o  -g -o tsp
			

solution.o: solution.cpp solution.h
			g++ -Wall -g -c solution.cpp

Map.o : Map.cpp Map.h
		g++ -Wall -g -c Map.cpp

TSP.o : TSP.cpp TSP.h
		g++ -Wall -g -c TSP.cpp

main.o: main.cpp
		  g++ -Wall -g -c main.cpp



