// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - RocketHoming.cpp
#include "RocketHoming.h"


RocketHoming::RocketHoming() : Rocket()
{
	DMG = 5;
	fuel = 50;
}

void RocketHoming::tick(unsigned long long)
{
	fuel -= 10;
}

void RocketHoming::update()
{}

RocketHoming::~RocketHoming()
{}