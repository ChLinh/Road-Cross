#pragma once
#include "CAnimal.h"
class Birds : public Animal
{
private:
	static Character cLeft, cRight;
public:
	Birds();
	Birds(int, int);
	Birds(int, int, bool);
	Birds(bool);
	~Birds() {}
	const Character& GetCharacter() override;
	Object* Clone(int, int) override;
	Objects GetShape() override;
};