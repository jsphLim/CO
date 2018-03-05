//
// Created by yue on 18-3-3.
//


#ifndef SA_TSPSA_H
#define SA_TSPSA_H

#include "SA.h"
#include "SA.cpp"
#include <vector>

class TSPSA : public SA<std::vector<int>>
{
private:
	size_t size;
protected:
	bool Balanced(int i);
public:
	TSPSA(StateImp<std::vector<int>> *stateImp);
};


#endif //SA_TSPSA_H
