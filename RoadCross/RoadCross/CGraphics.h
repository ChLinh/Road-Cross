#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


#define MaxHeight_Console 70
#define MaxWidth_Console 200

void GotoXY(int, int);
void GotoXY(COORD);
void ClearConsole();
void SetConsoleWindow(int witdh = MaxWidth_Console, int height = MaxHeight_Console);
