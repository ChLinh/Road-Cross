#pragma once
#include<vector>
#include<iostream>
#include"CGraphics.h"
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;
class Character
{
private:
	vector<string> str;
	int width, height;
public:
	Character();
	~Character();
	vector<string>& Get();
	int Width();
	int Height();
	void Draw(int, int, bool shap = true);
	Character(const char* filename);
};

