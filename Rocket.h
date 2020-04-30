// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - Rocket.h
// YOU ARE ALLOWED TO CHANGE THE CONTENTS OF THIS FILE
// BUT THE EXISTING METHOD DECLARATIONS MUST BE LEFT UNCHANGED
#pragma once
#include <memory>
#include "BossObserver.h"
#include "BossFSMState.h"


class BossFSMState;
class Rocket : public BossObserver // This is a virtual class that inherits another virtual class
{ 
public:
	~Rocket();
	static std::shared_ptr<Rocket> getRocket(); // This is a Factory function
	virtual void tick(unsigned long long) = 0; 
	virtual void update() = 0; // Inherited from BossObserver
	float getFuel();
protected:
	int DMG = 0;
	float fuel = 0;
	Rocket() : BossObserver() {};
};
