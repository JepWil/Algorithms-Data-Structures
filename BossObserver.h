// ASSIGNMENT 2 Programming in C/C++ 2 2017 - BY JEPPE WILLATZEN - 19/11/2017 - BossObserver.h
#pragma once
// YOU ARE ALLOWED TO CHANGE THE CONTENTS OF THIS FILE
// BUT THE EXISTING METHOD DECLARATIONS MUST BE LEFT UNCHANGE
class BossObserver	// This is an abstract class
{ 
public:
	BossObserver();
	~BossObserver();
	virtual void update() = 0;
};
