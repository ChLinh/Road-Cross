#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// Moving:
#pragma region KeyMove
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define ENTER 13
#pragma region Size

#define MaxHeight_Console 70
#define MaxWidth_Console 200
#define Height_Console_Menu 23		 
#define Width_Console_Menu	70	 
#define Width_OffSet 10
#define Height_OffSet 4
#define Left_Board_Edge Width_OffSet		 
#define Right_Board_Edge  (MaxWidth_Console - Width_OffSet - 1)	
#define Left_Board_Game 10 
#define Right_Board_Game Right_Board_Edge
#define Top_Board_Edge  Height_OffSet	 
#define Bottom_Board_Edge (MaxHeight_Console - Height_OffSet - 1)-25
#define Top_Board_Game Top_Board_Edge
#define Bottom_Board_Game (Bottom_Board_Edge - 0)

#define smallFontSizeW (short)GetSystemMetrics(SM_CXSCREEN)/MaxWidth_Console - 3	 
#define smallFontSizeH (short)GetSystemMetrics(SM_CYSCREEN)/MaxHeight_Console 	- 3	 

#define bigFontSizeW (short)GetSystemMetrics(SM_CXSCREEN)/Width_Console_Menu  - 10		 
#define bigFontSizeH (short)GetSystemMetrics(SM_CYSCREEN)/Height_Console_Menu  - 10		

#define DISTANCE 20
#define SIDE_WALK_HEIGHT 4
#define SLEEP_TIME 25
#define MINIMUM	1
#define MAXIMUM 4
#define MAX_LEVEL 5

#define Max_Line 4
#define BackGround_LightGreen   0x00A0  // background lightgreen
#define BackGround_LightRed    0x00C0  // background lightred

void TextColor(short);
void GotoXY(int, int);
void GotoXY(COORD);
void ClearConsole();
void SetConsoleWindow(int witdh = MaxWidth_Console, int height = MaxHeight_Console);
BOOL SetConsoleFontSize(COORD dwFontSize, const wchar_t* fontName);
SMALL_RECT GetWindowSize();
COORD GetCursorPosition();
void DrawBoard();
