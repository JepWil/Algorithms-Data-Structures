// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateAlive.h
#pragma once
#include "BossFSMStateAttac.h"
#include "Boss.h"


class BossFSMStateAlive : public BossFSMState
{
public:
	BossFSMStateAlive(std::shared_ptr<Boss> parent);
	~BossFSMStateAlive();
	void tick(unsigned long long timeMillis);
};

