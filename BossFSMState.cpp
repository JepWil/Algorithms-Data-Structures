// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMState.cpp
#include "BossFSMState.h"


BossFSMState::BossFSMState(std::shared_ptr<Boss> parent)
{
	this->parent = parent;
}

BossFSMState::~BossFSMState()
{}

void BossFSMState::tick(unsigned long long timeMillis) // abstract, so will be implemented by its children
{}

void BossFSMState::addRockets(std::shared_ptr<Rocket> r)
{
	parent->observers.push_back(r);
}