// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateAlive.cpp
#include "BossFSMStateAlive.h"


BossFSMStateAlive::BossFSMStateAlive(std::shared_ptr<Boss> parent) : BossFSMState(parent)
{	
	std::cout << "Boss is alive!\n";
}

BossFSMStateAlive::~BossFSMStateAlive()
{}

void BossFSMStateAlive::tick(unsigned long long timeMillis)
{
	if (parent->getHealth() < 100) // boss is aggro'd so he attac ...
	{
		this->parent->switchState(std::make_shared<BossFSMStateAttac>(this->parent));
	}
}