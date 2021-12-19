#include "CMenuGame.h"

MenuGame::MenuGame() {
	_H = Height_Console_Menu + 6;
	_W = Width_Console_Menu;
	//SetMenu("main");
	PastRow = 3;
	CurrRow = 4;
}
void MenuGame::ClearMenu()
{
	int x, y;
	vector<string> str = Menucha.Get();
	string temp = "";
	for (int row = 0; row < Menucha.Height(); row++)
	{
		int sizes = str[row].length();

		for (int i = 0; i < sizes; i++) {
			temp += " ";
		}

		x = FindMidW(str[row]) - 1;
		y = FindMidH() + row;
		GotoXY(x, y);
		printf(" %s ", temp.c_str());
	}
}