#pragma once
#include "CDinosaurs.h"

Character Dinosaurs::cLeft("Character\\Dinosaur_Left.txt");
Character Dinosaurs::cRight("Character\\Dinosaur_Right.txt");

Dinosaurs::Dinosaurs() {}

Dinosaurs::Dinosaurs(bool theDirec) : Animal(theDirec) {}

Dinosaurs::Dinosaurs(int x, int y) : Animal(x, y) {}

Dinosaurs::Dinosaurs(int x, int y, bool theDirec) : Animal(x, y, theDirec) {}

const Character& Dinosaurs::GetCharacter()
{
	if (dir == 0) {
		return cRight;
	}
	else {
		return cLeft;
	}
}

Object* Dinosaurs::Clone(int x, int y)
{
	return new Dinosaurs(x, y, dir);
}

Objects Dinosaurs::GetShape()
{
	return dinos;
}