// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateProtec.h
#pragma once
#include "Boss.h"


class BossFSMStateProtec : public BossFSMState
{
public:
	BossFSMStateProtec(std::shared_ptr<Boss> parent);
	~BossFSMStateProtec();
	void tick(unsigned long long timeMillis);
private:
	const int PROTECBOOST = 10; // Boss receives a health boost on entering its protec state
};

