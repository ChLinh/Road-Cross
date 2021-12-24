#pragma once
#include"CGraphics.h"
#include "CCharacter.h"

enum Objects
{
	birds, cars,dinos,trucks
};
class Object abstract
{
private:
	int X, Y;
protected:
	int preX;
	bool dir;//1: left,0: right
public:
	Object();
	Object(bool);
	Object(int, int, bool dirs = 1);
	~Object() {}
	int Width();
	int Height();
	void Draw();
	void ClearPre();
	COORD GetPos();
	void SetPos(int, int);
	virtual const Character& GetCharacter() = 0;
	virtual Object* Clone(int, int) = 0;
	virtual Objects GetShape() = 0;
	void Move();
};

