#pragma once
#include"CCharacter.h"
#include<conio.h>
#include<time.h>
class MenuGame {
private:
	int _W;
	int _H;
	Character Menucha;
	int PastRow;
	int CurrRow;
	int FindMidH();
	int FindMidW(string);
public:
	MenuGame();
	MenuGame(int, int);
	void SetMenu(const char*);
	/*~MenuGame();*/
	void ClearMenu();
};
