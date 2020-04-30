// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - RocketNuke.cpp
#include "RocketNuke.h"


RocketNuke::RocketNuke() : Rocket()
{
	DMG = 20;
	fuel = 100;
}

void RocketNuke::tick(unsigned long long)
{
	fuel -= 25;
}

void RocketNuke::update()
{}

RocketNuke::~RocketNuke()
{}