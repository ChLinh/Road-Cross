#pragma once
#include"CVehicals.h"
class Trucks : public Vehicals
{
private:
	static Character cLeft, cRight;
public:
	Trucks();
	Trucks(bool);
	Trucks(int, int, bool);
};

