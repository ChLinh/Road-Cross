#include "CStopLight.h"
StopLight::StopLight() {}
StopLight::StopLight(char sleep, bool redlight = false)
{
	if (redlight == true) { countDown = Red; }
	else { countDown = Green; }
	isRed = redlight;
	SetTime(sleep);
}
void StopLight::SetTime(char sleep)
{
	delay = sleep;
}
void StopLight::Draw(int x, int y)
{
	GotoXY(x, y);
	if (isRed == true)
	{
		TextColor(BackGround_LightRed);
		putchar(32);
	}
	else
	{
		TextColor(BackGround_LightGreen);
		putchar(32);
	}
}
void StopLight::UpdateTime()
{
	countDown -= delay;
	if (countDown <= 0)
	{
		if (isRed == true) { countDown = Red; }
		else { countDown = Green;}
		isRed = !isRed;
	}
}
void StopLight::Animation(int x, int y)
{
		Draw(x, y);
		UpdateTime();
		Sleep(delay);
}
bool StopLight::IsRed()
{
	return isRed;
}
