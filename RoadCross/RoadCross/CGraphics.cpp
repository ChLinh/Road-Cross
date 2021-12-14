#pragma once
#include "CGraphics.h"
#include <fstream>
using namespace std;

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE ConsoleHanle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(ConsoleHanle, coord);
}

void GotoXY(COORD coord)
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(ConsoleHandle, coord);
}

void ClearConsole()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(ConsoleHandle, &csbi);

	std::string str(csbi.srWindow.Right + 1, ' ');
	for (int i = 0; i <= csbi.srWindow.Bottom; i++) {
		GotoXY(0, i);
		printf("%s", str.c_str());
	}
}

void SetConsoleWindow(int width, int height)
{
	HWND consoleWindow = GetConsoleWindow();
	LONG Style = GetWindowLong(consoleWindow, GWL_STYLE);
	Style = Style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, Style);
	CONSOLE_CURSOR_INFO info;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(ConsoleHandle, &info);
	COORD ConsoleBufferSize = { width, height };
	SetConsoleScreenBufferSize(ConsoleHandle, ConsoleBufferSize);
	SMALL_RECT Rect = { 0,0,ConsoleBufferSize.X - 1,ConsoleBufferSize.Y - 1 };
	SetConsoleWindowInfo(ConsoleHandle, TRUE, &Rect);
}

void TextColor(short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

BOOL SetConsoleFontSize(COORD dwFontSize, const wchar_t* fontName) {
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info{ sizeof(CONSOLE_FONT_INFOEX) };
	if (!GetCurrentConsoleFontEx(Out, false, &info))
		return false;
	info.dwFontSize = dwFontSize;
	wcscpy_s(info.FaceName, fontName);
	return SetCurrentConsoleFontEx(Out, false, &info);
}

COORD GetCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD pos;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(ConsoleHandle, &csbi)) {
		pos = { 0,0 };
	}

	pos = csbi.dwCursorPosition;
	return pos;
}

SMALL_RECT GetWindowSize()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	CONSOLE_CURSOR_INFO info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &csbi);
	return csbi.srWindow;
}