// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossFSMStateAttac.cpp
#include "BossFSMStateAttac.h"
#include "BossFSMStateProtec.h"


BossFSMStateAttac::BossFSMStateAttac(std::shared_ptr<Boss> parent) : BossFSMState(parent)
{}

BossFSMStateAttac::~BossFSMStateAttac()
{}

void BossFSMStateAttac::tick(unsigned long long timeMillis)
{
	std::cout << "Attac!\n";
	addRockets(Rocket::getRocket()); // calls the parent state (BOSSFSMState.h) addRockets() to store rockets in a vector
	std::cout << "Firing rocket!\n";
	if (parent->getHealth() <= 20) // ...and eventually he protec
	{
		this->parent->switchState(std::make_shared<BossFSMStateProtec>(this->parent));
	}
}