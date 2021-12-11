#pragma once
#include<vector>
#include<iostream>
#include"CGraphics.h"
using namespace std;
class Character
{
private:
	vector<string> str;
	int width, height;
public:
	Character();
	~Character();
	int Width();
	int Height();
	void Draw(int, int, bool shap = true);
};

