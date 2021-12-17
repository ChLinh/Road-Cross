#pragma once
#include "CBirds.h"

Character Birds::cLeft("Character\\Bird_Left.txt");
Character Birds::cRight("Character\\Bird_Right.txt");

Birds::Birds() {}

Birds::Birds(bool theDirec) : Animal(theDirec) {}

Birds::Birds(int x, int y) : Animal(x, y) {}

Birds::Birds(int x, int y, bool theDirec) : Animal(x, y, theDirec) {}

const Character& Birds::GetCharacter()
{
	if (dir == 0) {
		return cRight;
	}
	else {
		return cLeft;
	}
}

Object* Birds::Clone(int x, int y)
{
	return new Birds(x, y, dir);
}

Objects Birds::GetShape()
{
	return birds;
}