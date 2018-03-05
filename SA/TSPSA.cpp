//
// Created by yue on 18-3-3.
//


#include "TSPSA.h"

TSPSA::TSPSA(StateImp<std::vector<int>> *stateImp) : SA<std::vector<int>>(stateImp)
{
	size = stateImp->InitState()->size();
}

bool TSPSA::Balanced(int i)
{
	return i > 100 * size;
}
