#include<iostream>
#include "CMenuGame.h"
#include"CGame.h"
#include"CObject.h"
using namespace std;
void ThreadIntro()
{
	Character cha("Character\\INTRO.txt");
	int h = cha.Height();
	while (h > 0)
	{
		cha.Draw(11, 0);
		Sleep(100);
		h--;
	}
}

void main()
{
	thread t1(ThreadIntro);
	Game game;
	game.StartGame();
}