// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - Boss.h
// YOU ARE ALLOWED TO CHANGE THE CONTENTS OF THIS FILE
// BUT THE EXISTING METHOD DECLARATIONS MUST BE LEFT UNCHANGED
#pragma once
#include <memory>
#include <vector>
#include "Rocket.h"


class BossFSMState;
class Boss
{
public:
	Boss();
	~Boss();
	std::vector<std::shared_ptr<BossObserver>> observers;
	void switchState(std::shared_ptr<BossFSMState> state);
	std::shared_ptr<BossFSMState> getState();
	void tick(unsigned long long timeMillis);
	void takeDamage(int damage);
	int getHealth();
	void setHealth(int hp);
private:
	std::shared_ptr<BossFSMState> currentState = nullptr;
	int health;
};
