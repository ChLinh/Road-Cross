#pragma once
#include"CAnimal.h"
class Dinosaurs :public Animal
{
private:
	static Character cLeft, cRight;
public:
	Dinosaurs();
	Dinosaurs(int, int);
	Dinosaurs(int, int, bool);
	Dinosaurs(bool);
	~Dinosaurs() {}
};

