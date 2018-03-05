all : sa_tsp

sa_tsp : SA.o TSPSA.o StateImp.o TSPStateImp.o main.o
	g++ SA.o main.o TSPSA.o StateImp.o TSPStateImp.o -g -o sa_tsp



SA.o : SA.cpp SA.h
	g++ -Wall -g -c SA.cpp

TSPSA.o : TSPSA.cpp TSPSA.h
	g++ -Wall -g -c TSPSA.cpp

StateImp.o : StateImp.cpp StateImp.h
	g++ -Wall -g -c StateImp.cpp

TSPStateImp.o : TSPStateImp.cpp TSPStateImp.h
	g++ -Wall -g -c TSPStateImp.cpp

main.o : main.cpp
	g++ -Wall -g -c main.cpp
