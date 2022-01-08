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

void Exit(thread* t)
{
	ClearConsole();
	t->join();
}
void main()
{
	thread t1(ThreadIntro);
	SetConsoleOutputCP(437);
	char ch;
	while (1)
	{
		Game game;
		game.StartGame();
		ch = _getch();
		if (ch == ENTER)
		{
			Exit(&t1);
			break;
		}
	}

}