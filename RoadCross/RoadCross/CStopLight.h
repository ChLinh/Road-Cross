#pragma once
#include "CGraphics.h"
#define Red 4000		 
#define Green 3000	 
class StopLight
{
private:
	int countDown;
	bool isRed;
	int delay;
	void SetTime(char);
public:
	StopLight();
	StopLight(char, bool);
	void Draw(int, int);
	void UpdateTime();
	void Animation(int, int);
	bool IsRed();
	~StopLight() {}
};

