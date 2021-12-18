#include "CStopLight.h"
StopLight::StopLight() {}
StopLight::StopLight(char sleep, bool redlight = false)
{
	if (redlight == true) { countDown = Red; }
	else { countDown = Green; }
	isRed = redlight;
	warning = false;
	countTime = 0;
	hidden = false;
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
		if (warning == false)
			TextColor(BackGround_LightRed);
		else
		{
			if (hidden == true)
				TextColor(BACKGROUND_RED);
			else
				TextColor(BackGround_LightRed);
		}
		putchar(32);
	}
	else
	{
		if (warning == false)
			TextColor(BackGround_LightGreen);
		else
		{
			if (hidden == true)
				TextColor(BACKGROUND_GREEN);
			else
				TextColor(BackGround_LightGreen);
		}
		putchar(32);
	}
}
void StopLight::UpdateTime()
{
	if (countTime == ONE_SECOND && countDown > TIME_BLINKING)
	{
		countDown -= countTime;
		countTime = 0;
	}

	if (countDown == TIME_BLINKING)
	{
		warning = true;
		hidden = true;
	}
	if (countTime == ONE_SECOND / 2 && warning == true)
	{
		countDown -= countTime;
		countTime = 0;
		hidden = !hidden;
	}
	if (countDown == 0)
	{
		if (isRed == true) { countDown = Red; }
		else { countDown = Green; }
		isRed = !isRed;
		warning = false;
	}
	countTime += delay;
}
void StopLight::Animation(int x, int y)
{
	while (1)
	{
		Draw(x, y);
		UpdateTime();
		Sleep(delay);
	}
}
bool StopLight::IsRed()
{
	return isRed;
}
