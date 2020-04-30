// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateAttac.h
#pragma once
#include "BossFSMState.h"


class BossFSMStateAttac : public BossFSMState
{
public:
	BossFSMStateAttac(std::shared_ptr<Boss> parent);
	~BossFSMStateAttac();
	void tick(unsigned long long timeMillis);
};

