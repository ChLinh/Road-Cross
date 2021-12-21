#pragma once
#include"CCharacter.h"
#include<conio.h>
#include<time.h>
class MenuGame {
private:
	int _W;
	int _H;
	Character Menucha;
	Character Guide;
	int PastRow;
	int CurrRow;
	int FindMidH();
	int FindMidW(string);
	int FindLongestPos(vector<string>);
public:
	MenuGame();
	MenuGame(int, int);
	void SetMenu(const char*);
	~MenuGame();
	void ClearMenu();
};
