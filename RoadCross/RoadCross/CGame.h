#pragma once
#include "CLine.h"
#include <filesystem>
#include "CPeople.h"
#include <stdlib.h>
using namespace std::experimental::filesystem;

class Game
{
private:
	vector<Line> line;
	People people;
public:
	vector<string> GetFileName(const char* path);
	void DrawGame();
};

