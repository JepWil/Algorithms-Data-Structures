// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - Boss.cpp
#include "Boss.h"
#include "BossFSMStateAlive.h"


Boss::Boss() 
{
	health = 100;
	std::shared_ptr<BossFSMState> alive = std::make_shared<BossFSMStateAlive>(std::shared_ptr<Boss>(this, [](auto a) {})); // [](auto a) {} is a generic lambda function which prevents the destructor from being called twice
	switchState(alive);
}

Boss::~Boss() 
{}

void Boss::switchState(std::shared_ptr<BossFSMState> state)
{
	currentState = state;
}

std::shared_ptr<BossFSMState> Boss::getState()
{
	return currentState;
}

void Boss::tick(unsigned long long timeMillis)
{
	currentState->tick(timeMillis);
}

void Boss::takeDamage(int damage) 
{
	health -= damage;
}

int Boss::getHealth() 
{
	return health;
}

void Boss::setHealth(int hp)
{
	health = hp;
}


