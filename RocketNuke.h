// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - RocketNuke.h
#pragma once
#include "Rocket.h"


class RocketNuke : public Rocket
{
public:
	void tick(unsigned long long);
	void update();
	~RocketNuke();
	RocketNuke();
};

