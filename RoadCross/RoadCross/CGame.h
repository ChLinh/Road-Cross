#pragma once
#include "CLine.h"
#include <filesystem>
#include "CPeople.h"
#include <stdlib.h>
#define WAITING 10
using namespace std::experimental::filesystem;

class Game
{
private:
	vector<Line> line;
	People people;
	int level;
public:
	vector<string> GetFileName(const char* path);
	void DrawGame();
	void UpdatePosPeople(const char MOVING);
	void UpdatePosObject();
	bool IsImpact();
	bool IsExistFile(const char* fileName);
	void DrawLevel();
};

