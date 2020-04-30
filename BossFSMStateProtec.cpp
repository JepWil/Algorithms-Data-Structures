// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateProtec.cpp
#include "BossFSMStateProtec.h"


BossFSMStateProtec::BossFSMStateProtec(std::shared_ptr<Boss> parent) : BossFSMState(parent)
{}

BossFSMStateProtec::~BossFSMStateProtec()
{}

void BossFSMStateProtec::tick(unsigned long long timeMillis)
{
	std::cout << "Protec!\n";
	addRockets(Rocket::getRocket()); // calls the parent state (BOSSFSMState.h) addRockets() to store rockets in a vector
	std::cout << "Firing rocket!\n";
	for (static int counter = 0; counter < 1; counter++) // static to make sure the boost doesn't happen every tick()
	{
		this->parent->setHealth(this->parent->getHealth() + PROTECBOOST); // PROTECBOOST gives the boss additional health the first time it enters its protec state
	}
}