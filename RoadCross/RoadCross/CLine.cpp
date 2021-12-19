#include "CLine.h"
Line::Line()
{
	width = Right_Board_Game - Left_Board_Game + 1;
}
Line::Line(COORD coord, vector<Object*> v, bool thedir, short SleepTime)
{
	obj = v;
	pos = coord;
	dir = thedir;
	height = obj[0]->Height() + 1;
	width = Right_Board_Game - Left_Board_Game + 1;
	sleep = SleepTime;
	timeCount = 0;
	if (v[0]->GetShape() != dinos && v[0]->GetShape() != birds)
		stop = new StopLight(SleepTime, rand() % 2);
	else
		stop = nullptr;
}