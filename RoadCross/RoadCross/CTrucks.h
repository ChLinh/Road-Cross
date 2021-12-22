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
	const Character& GetCharacter() override;
	Object* Clone(int, int) override;
	Objects GetShape() override;
};

