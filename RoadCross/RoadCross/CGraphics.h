#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void GotoXY(int, int);

#define MaxHeight_Console 70
#define MaxWidth_Console 200

void SetConsoleWindow(int witdh = MaxWidth_Console, int height = MaxHeight_Console);
