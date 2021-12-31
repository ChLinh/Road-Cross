#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<experimental/filesystem>
#include "CGame.h"
using namespace std;

vector<string> Game::GetFileName(const char* path)
{
	vector<string> v;
	experimental::filesystem::path p(path);

	for (auto i = directory_iterator(p); i != directory_iterator(); i++)
	{
		if (!is_directory(i->path()))
			v.push_back(i->path().filename().string());
	}

	return v;
}
void Game::DrawGame()
{
	int n = line.size();
	for_each(line.begin(), line.end(), mem_fn(&Line::Draw));
	people.Draw();
}

void Game::UpdatePosPeople(const char MOVING)
{
	people.Move(MOVING);
}

void Game::UpdatePosObject()
{
	//int n = line.size();
	int n = 4;
	for (int i = 0; i < n; i++) {
		line[i].PosUpdate();
	}
}

bool Game::IsImpact()
{
	const short people_top = people.GetPos().Y;
	const short people_bot = people.GetPos().Y + people.Height() - 1;

	if (people_bot <= line[0].GetPos().Y) {
		return false;
	}

	if (people_top > line[Max_Line - 1].GetPos().Y + line[Max_Line - 1].Height()) {
		return false;
	}

	for (int i = 0; i < Max_Line; i++) {

		const short line_top = line[i].GetPos().Y;
		const short line_bot = line[i].GetPos().Y + line[i].Height() - 1;

		if (line_top >= people_bot) {
			break;
		}

		if ((people_top >= line_top && people_top <= line_bot)
			|| (people_bot > line_top && people_bot <= line_bot)) {

			if (line[i].IsImpact(people)) {
				return true;
			}
		}
	}

	return false;
}
void Game::DrawLevel()
{
	string s = to_string(level);
	Character cha("Character\\Level.txt");

	for (int i = 0; i < s.size(); i++) {
		Character temp = Character((string("Character\\") + s[i]).c_str());
		cha = cha + temp;
	}

	SMALL_RECT rect = GetWindowSize();
	int x = (rect.Right + 1 - cha.Width()) / 2;
	int y = (rect.Bottom + 1 - cha.Height()) / 2;


	//TextColor(BACKGROUND_BLACK | FOREGROUND_LIGHTCYAN);

	ClearConsole();
	cha.Draw(x, y, false);

	Character loading = Character("Character\\Loading.txt");
	//TextColor(FOREGROUND_YELLOW);
	for (int i = 0; i < WAITING; i++)
	{
		loading.Draw(x - 70 + loading.Width() * i, y + cha.Height() + 1, false);
		Sleep(100);
	}

	ClearConsole();
	//TextColor(BACKGROUND_BLACK | FOREGROUND_WHITE);
}
bool Game::IsExistFile(const char* fileName)
{
	fstream inFile(fileName);

	if (inFile)
	{
		inFile.close();
		return true;
	}

	return false;
}
void Game::Init()
{

	int pos;
	int arr[8] = { 0 };
	Character cha;
	short height = Height_OffSet + 1 + SIDE_WALK_HEIGHT + 1;

	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 0; i < 8; i++)
		arr[i] = i % 4;


	int n = 0;
	int x;
	Object* obj;
	bool direc;
	COORD linePos;
	for (int i = 0; i < 8; i++) {

		n = (MINIMUM + level) + 1;
		x = rand() % (Right_Board_Game - Left_Board_Game - 1) + (Left_Board_Game + 1);
		direc = (i % 2 == 0 ? 1 : 0);
		vector<Object*> v;

		switch (arr[i])
		{
		case 1:
			if (level == 5)
				n = n - 1;
			v.push_back(new Cars(0, 0, direc));
			for (int j = 1; j < n; j++) {
				obj = new Cars(x, height + 1, direc);
				v.push_back(obj);

				if (direc == 1) {
					x += obj->Width() + DISTANCE;
				}
				else {
					x -= obj->Width() + DISTANCE;
				}
			}

			linePos = { Left_Board_Game + 1 ,height };
			line.push_back(Line(linePos, v, direc, SLEEP_TIME));
			break;

		case 2:
			v.push_back(new Birds(0, 0, direc));

			for (int j = 1; j < n; j++) {
				obj = new Birds(x, height + 1, direc);
				v.push_back(obj);

				if (direc == 1) {
					x += obj->Width() + DISTANCE;
				}
				else {
					x -= obj->Width() + DISTANCE;
				}
			}

			linePos = { Left_Board_Game + 1,height };
			line.push_back(Line(linePos, v, direc, SLEEP_TIME));
			break;

		case 3:
			if (level == 5)
				n = n - 1;
			v.push_back(new Trucks(0, 0, direc));

			for (int j = 1; j < n - 1; j++) {
				obj = new Trucks(x, height + 1, direc);
				v.push_back(obj);

				if (direc == 1) {
					x += obj->Width() + DISTANCE;
				}
				else {
					x -= obj->Width() + DISTANCE;
				}
			}

			linePos = { Left_Board_Game + 1,height };
			line.push_back(Line(linePos, v, direc, SLEEP_TIME));
			break;

		case 0:
			if (level == 5)
				n = n - 1;
			v.push_back(new Dinosaurs(0, 0, direc));

			for (int j = 1; j < n - 1; j++) {
				obj = new Dinosaurs(x, height + 1, direc);
				v.push_back(obj);

				if (direc == 1) {
					x += obj->Width() + DISTANCE;
				}
				else {
					x -= obj->Width() + DISTANCE;
				}
			}

			linePos = { Left_Board_Game + 1,height };
			line.push_back(Line(linePos, v, direc, SLEEP_TIME));

			break;

		}

		height += line[i].Height() + 1;
		v.clear();
	}

	people = People((Left_Board_Game + Right_Board_Game) / 2, Bottom_Board_Edge - people.Height());
	people.SetLive(true);
	checkin = false;
}

