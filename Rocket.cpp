// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - Rocket.cpp
#include "Rocket.h"
#include <random>
#include "RocketNuke.h"
#include "RocketHoming.h"


int random(int min, int max);

std::shared_ptr<Rocket> Rocket::getRocket() // Generates a random number and returns a Rocket type based on that number.
{
	std::shared_ptr<Rocket> r = nullptr;
	int randomnumber = random(0, 10);

	if (randomnumber <= 5)
	{
		r = std::make_shared<RocketNuke>();
		return r;
	}
	else if (randomnumber > 5)
	{
		r = std::make_shared<RocketHoming>();
		return r;
	}
	else
	{
		std::cerr << "Could not fetch rocket!\n";
		return r;
	}
}

Rocket::~Rocket() {}

float Rocket::getFuel() 
{
	return fuel;
}

// random number generator acquired from our previous course assignments; courtesy of ulfben, used with permission.
int random(int min, int max)
{
	static std::random_device rd; // obtain a random seed from hardware
	static std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max); //	define the range
	return distr(eng);
}