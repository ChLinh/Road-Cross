#pragma once
#include<vector>
#include<iostream>

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
};

