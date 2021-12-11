#include "CObject.h"
#include "CObject.h"
Object::Object() : dir(0)
{
	preX = -1;
}
Object::Object(bool theDirec)
{
	dir = theDirec;
	preX = -1;
}
Object::Object(int x, int y, bool theDirec)
{
	X = x;
	Y = y;
	dir = theDirec;
	preX = -1;
}

int Object::Width()
{
	Character cha = GetCharacter();
	return cha.Width();
}
int Object::Height()
{
	Character cha = GetCharacter();
	return cha.Height();
}