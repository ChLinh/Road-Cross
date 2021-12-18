#pragma once
#include"CCharacter.h"
#include<conio.h>
#include<time.h>
class MenuGame {
private:
	int _W;
	int _H;
	int PastRow;
	int CurrRow;
public:
	MenuGame();
	MenuGame(int, int);
	void SetMenu(const char*);
	~MenuGame();
};
