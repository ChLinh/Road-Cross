#pragma once
#include<vector>
#include<codecvt>
#include<iostream>
#include"CGraphics.h"
#include<algorithm>
#include <fstream>
#include <sstream>
#include<mutex>
#include<stdio.h>
#include<conio.h>
#include <Windows.h>
using namespace std;
static mutex theLock;
class Character
{
	friend class People;
private:
	vector<string> str;
	int width, height;
public:
	Character();
	vector<string>& Get();
	int Width();
	void Set(const char*);
	int Height();
	void Draw(int, int, bool shap = true);
	Character(const char* filename);
	Character operator + (Character&);
	void Write(ostream&);
	void Read(istream&);
	~Character();
};

