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
	void Up();
	void Down();
	void Enter();
public:
	MenuGame();
	MenuGame(int, int);
	void SetMenu(const char*);
	~MenuGame();
	void Draw();
	string Slection();
	void ClearMenu();
};
