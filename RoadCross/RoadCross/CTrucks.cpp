#include "CTrucks.h"
Character Trucks::cLeft("Character\\Truck_Left.txt");
Character Trucks::cRight("Character\\Truck_Right.txt");
Trucks::Trucks() {}
Trucks::Trucks(bool theDirec) : Vehicals(theDirec) {}
Trucks::Trucks(int x, int y, bool theDirec) : Vehicals(x, y, theDirec) {}
const Character& Trucks::GetCharacter()
{
	if (dir == 0) {
		return cRight;
	}
	else {
		return cLeft;
	}
}

Object* Trucks::Clone(int x, int y)
{
	return new Trucks(x, y, dir);
}

Objects Trucks::GetShape()
{
	return	trucks;
}