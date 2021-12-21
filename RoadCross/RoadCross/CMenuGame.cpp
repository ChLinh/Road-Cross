#include "CMenuGame.h"

MenuGame::~MenuGame() {};

int MenuGame::FindMidH()
{
	return _H / 2 - Menucha.Height() / 2 - Menucha.Height() % 2;
}

int MenuGame::FindMidW(string Title)
{
	return _W / 2 - Title.length() / 2 - Title.length() % 2;
}

void MenuGame::SetMenu(const char* Type)
{
	if (strcmp(Type, "main") == 0)
		Menucha.Set("Character\\Main_Menu.txt");
	else if (strcmp(Type, "pause") == 0)
		Menucha.Set("Character\\Pause_Menu.txt");
	else if (strcmp(Type, "lose") == 0)
		Menucha.Set("Character\\Lose_Menu.txt");
	else if (strcmp(Type, "yes_no") == 0)
		Menucha.Set("Character\\Yes_No_Menu.txt");
	else if (strcmp(Type, "continue") == 0)
		Menucha.Set("Character\\Continue_Menu.txt");
	else if (strcmp(Type, "on_off") == 0)
		Menucha.Set("Character\\On_Off_Menu.txt");
	Guide.Set("Character\\Guide.txt");
}

MenuGame::MenuGame() {
	_H = Height_Console_Menu + 6;
	_W = Width_Console_Menu;
	SetMenu("main");
	PastRow = 3;
	CurrRow = 4;
}
MenuGame::MenuGame(int W, int H)
{
	_W = W;
	_H = H;
	SetMenu("main");
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

int MenuGame::FindLongestPos(vector<string> text)
{
	int pos, longest = text[0].length();
	for (int i = 0; i < text.size(); i++)
	{
		if (longest < text[i].length())
		{
			longest = text[i].length();
			pos = i;
		}
	}
	return pos;
}

void MenuGame::Up()
{
	if (CurrRow == 4)
		return;
	PastRow = CurrRow;
	CurrRow--;
}

void MenuGame::Down()
{
	if (CurrRow == Menucha.Height() - 5) return;
	PastRow = CurrRow;
	CurrRow++;
}
void MenuGame::Enter() {};

void MenuGame::Clear()
{
	int x, y;
	vector<string> str = Menucha.Get();
	string temp = "";
	for (int row = 0; row < Menucha.Height(); row++)
	{
		int sizes = str[row].length();
		for (int i = 0; i < sizes; i++)
		{
			temp += " ";
		}
		temp += " ";
		x = FindMidW(str[row]) - 1;
		y = FindMidH() + row;
		GotoXY(x, y);
		printf("%s", temp.c_str());
	}
}

void MenuGame::Control(char key)
{
	switch (key)
	{
	case'w':
	case UP:
		this->Up(); break;
	case DOWN:
	case's': this->Down(); break;
	case ENTER: this->Enter(); break;
	}
}