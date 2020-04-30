// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMState.h
#pragma once
#include <memory>
#include "Boss.h"
#include "Rocket.h"
#include <iostream>


class Rocket;
class Boss;
class BossFSMState
{
public:
	BossFSMState(std::shared_ptr<Boss> parent);
	~BossFSMState();
	virtual void tick(unsigned long long timeMillis) = 0;
	void addRockets(std::shared_ptr<Rocket> r); // stores rockets from getRockets()-factory in a vector
protected:
	std::shared_ptr<Boss> parent = nullptr;
};

