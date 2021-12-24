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
void Object::Draw()
{
	TextColor(7);
	Character cha = GetCharacter();
	int width = cha.Width();
	if (preX > 0 && preX != Right_Board_Game && preX != Left_Board_Game) {
		ClearPre();
	}
	if (dir == 1) {

		if (X >= Right_Board_Game) {
			return;
		}
	}
	else if (dir == 0) {
		if (X + width - 1 < Left_Board_Game) {
			return;
		}
		else if (X < Right_Board_Game && X + width - 1 > Right_Board_Game) {
			Object* newObj = this->Clone(Left_Board_Game - (Right_Board_Game - X) + 1, Y);
			newObj->Draw();
			delete newObj;
		}
	}
	cha.Draw(X, Y);
}
void Object::ClearPre()
{
	Character cha = GetCharacter();
	int height = cha.Height();
	for (int i = 0; i < height; i++) {
		GotoXY(preX, Y + i);
		cout << " ";
	}
}
COORD Object::GetPos()
{
	COORD pos = { X,Y };
	return pos;
}
void Object::SetPos(int x, int y)
{
	X = x;
	Y = y;
}

void Object::Move()
{

	Character cha = GetCharacter();
	int width = cha.Width();
	COORD pos;
	if (dir == 1) {
		if (X + width - 1 < Right_Board_Edge) {
			preX = X + width - 1;
		}

		if (X + width - 1 > Left_Board_Game + 1) {
			X--;
		}
		else {
			X = Right_Board_Game - width + 1;
		}
	}
	else {
		if (X > Left_Board_Edge) {
			preX = X;
		}

		if (X < Right_Board_Game) {
			X++;
		}
		else {
			X = Left_Board_Game + 1;
		}
	}

}