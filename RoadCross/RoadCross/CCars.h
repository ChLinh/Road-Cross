#pragma once
#include"CVehicals.h"
class Cars : public Vehicals
{
private:
	static Character cLeft, cRight;
public:
	Cars();
	Cars(bool);
	Cars(int, int, bool);
	const Character& GetCharacter() override;
	Object* Clone(int, int) override;
	Objects GetShape() override;
};

