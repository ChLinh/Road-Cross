#include "CCars.h"
Character Cars::cLeft("Character\\Car_Left.txt");
Character Cars::cRight("Character\\Car_Right.txt");
Cars::Cars() {}
Cars::Cars(bool theDirec) : Vehicals(theDirec) {}
Cars::Cars(int x, int y, bool theDirec) : Vehicals(x, y, theDirec) {}
const Character& Cars::GetCharacter()
{
	if (dir == 0) {
		return cRight;
	}
	else {
		return cLeft;
	}
}
Object* Cars::Clone(int x, int y)
{
	return new Cars(x, y, dir);
}
Objects Cars::GetShape()
{
	return	cars;
}