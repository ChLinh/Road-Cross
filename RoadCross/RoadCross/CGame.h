#pragma once
#include"CPeople.h"
#include"CCars.h"
#include"CTrucks.h"
#include"CBirds.h"
#include"CDinosaurs.h"
#include"CMenuGame.h"
#include"CLine.h"
#include <filesystem>
#include <stdlib.h>
#define WAITING 10
using namespace std::experimental::filesystem;

class Game
{
private:
	static int LEVEL;
	vector<Line> line;
	People people;
	int level;
	MenuGame menu;
	int Life;
	thread t;
public:
	bool checkin;
	vector<string> GetFileName(const char* path);
	void DrawGame();
	void Init();
	void ThreadFunction();
	bool IsLevelUp();
	void LevelUp();
	void Run();
	void ResumeGame();
	void UpdatePosPeople(const char MOVING);
	void UpdatePosObject();
	bool IsImpact();
	bool IsExistFile(const char* fileName);
	void DrawLevel();
	void DrawMessage(string type);
	void DrawCurrentLevel();

	
	void ProcessDead();
	void DrawObject();
	void DrawPeople();
	void DrawSeparator();
	void ClearBoard() const;
	void Located();
	void ResetGame();
	void PauseGame(char);
	void ExitGame();
	void SettingGame();
	void StartGame();

	void LoadGame();
};

