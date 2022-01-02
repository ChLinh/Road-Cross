#define _CRT_SECURE_NO_WARNINGS
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

	ClearConsole();
	cha.Draw(x, y, false);

	Character loading = Character("Character\\Loading.txt");
	for (int i = 0; i < WAITING; i++)
	{
		loading.Draw(x - 70 + loading.Width() * i, y + cha.Height() + 1, false);
		Sleep(100);
	}

	ClearConsole();
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
void Game::DrawCurrentLevel()
{
	string s = to_string(level);
	Character cha("Character\\Level.txt");
	for (int i = 0; i < s.size(); i++) {
		Character temp = Character((string("Character\\") + s[i]).c_str());
		cha = cha + temp;
	}
	int x = Right_Board_Edge + 1;
	int y = Bottom_Board_Edge - cha.Height() - 7;
	cha.Draw(x, y, false);
	if (Life > 0)
	{
		Character life("Character\\People.txt");
		Character test("Character\\People.txt");
		for (int i = 1; i < Life; i++)
		{
			life = life + test;
		}
		life.Draw(x + life.Width() / 2, y + cha.Height() + 1, false);
	}

}
void Game::DrawMessage(string type)
{
	Character cha;
	if (type == "lose") {
		cha = Character("Character\\YOULOSE.txt");
	}
	else if (type == "gameover")
	{
		cha = Character("Character\\GAMEOVER.txt");
	}
	else if (type == "win") {
		cha = Character("Character\\YOUWIN.txt");
	}

	SMALL_RECT shape = GetWindowSize();
	int x = (shape.Right + 1 - cha.Width()) / 2;
	int y = (shape.Bottom + 1 - cha.Height()) / 2;

	ClearConsole();
	cha.Draw(x, y, false);
	Sleep(2500);
	ClearConsole();

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
bool Game::IsLevelUp()
{
	const short people_bot = people.GetPos().Y + people.Height() - 1;

	return people_bot < Height_OffSet + 1 + SIDE_WALK_HEIGHT;
}
void Game::LevelUp()
{
	ClearConsole();
	SuspendThread(t.native_handle());
	Located();
	if (level == MAX_LEVEL) {
		DrawMessage("win");
		Sleep(1000);
		level = 1;
	}
	else
		++level;
	Init();
	DrawLevel();
	DrawBoard();
	DrawCurrentLevel();
	DrawPeople();
	ResumeThread(t.native_handle());
}

void Game::ProcessDead()
{
	TextColor(7);
	Sleep(2000);
	(Life == 0) ? DrawMessage("gameover") : DrawMessage("lose");

	ClearConsole();
	SetConsoleFontSize({ bigFontSizeW, bigFontSizeH }, L"Consolas");
	SetConsoleWindow(Width_Console_Menu, Height_Console_Menu);
	if (Life == 0)
	{
		menu.SetMenu("lose");
	}
	else
	{
		menu.SetMenu("continue");
	}

	while (true)
	{
		const string select = menu.Slection();
		menu.ClearMenu();
		if (select == "CONTINUE") {

			SetConsoleFontSize({ smallFontSizeW,smallFontSizeH }, L"Lucida Console");
			SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
			menu.Clear();
			Life--;
			ResetGame();
			DrawBoard();
			DrawCurrentLevel();
			DrawPeople();
			return;
		}
		if (select == "MAIN MENU") {
			Located();
			Life = 3;
			ClearConsole();
			throw string("MAIN MENU");
		}
	}
}

void Game::DrawObject()
{

	//for_each(line.begin(), line.end(), mem_fn(&Line::Draw));
	for (int i = 0; i < 4; i++)
		line[i].Draw();
}

void Game::DrawPeople()
{
	people.Draw();
}

void Game::DrawSeparator()
{
	int y = Height_OffSet + 1 + SIDE_WALK_HEIGHT;
	string s[5];
	const short people_top = people.GetPos().Y;
	const short people_bot = people_top + people.Height() - 1;
	const short people_left = people.GetPos().X;
	const short people_right = people_left + people.Width() - 1;

	for (int k = 0; k < 5; k++) {
		if (k == 0 || k == 4) {
			if (people_top <= y && people_bot >= y) {
				for (int i = Left_Board_Game + 1; i < people_left; i++) {
					s[k] += '_';
				}

				s[k] += people.GetCharacter().Get()[y - people_top];
				for (int i = people_right + 1; i < Right_Board_Game; i++) {
					s[k] += '_';
				}
			}
			else {
				for (int i = Left_Board_Game + 1; i < Right_Board_Game; i++) {
					s[k] += '_';
				}
			}
		}
		else {
			if (people_top <= y && people_bot >= y) {
				for (int i = Left_Board_Game + 1; i < people_left; i++) {
					s[k] += '_';
				}

				s[k] += people.GetCharacter().Get()[y - people_top];
				for (int i = people_right + 1; i < Right_Board_Game; i++) {
					s[k] += '_';

				}
			}
			else {
				for (int i = Left_Board_Game + 1; i < Right_Board_Game; i++) {
					s[k] += '_';

				}
			}
		}

		if (k < 4) {
			y = line[k].GetPos().Y + line[k].Height();
		}
	}

	y = Height_OffSet + 1 + SIDE_WALK_HEIGHT;
	for (int i = 0; i < 5; i++) {
		GotoXY(Left_Board_Game + 1, y);
		cout << s[i];
		if (i < 4) {
			y = line[i].GetPos().Y + line[i].Height();
		}
	}
}
void Game::ThreadFunction()
{
	while (true) {

		UpdatePosObject();
		checkin = true;
		lock_guard<mutex>* lock = new lock_guard<mutex>(theLock);
		DrawSeparator();
		DrawObject();
		delete lock;
		if (IsImpact())
		{
			TextColor(4);
			for (int i = 0; i < WAITING; i++)
			{
				people.Draw(false);
			}
			people.SetLive(false);
			try
			{
				ProcessDead();
			}
			catch (string s)
			{
				if (s == "MAIN MENU") checkin = false;
				return;
			}
		}
		checkin = false;
		Sleep(SLEEP_TIME);
	}
}


void Game::ClearBoard() const
{
	string s(Right_Board_Game - Left_Board_Game + 1, ' ');

	for (int i = Top_Board_Game; i <= Bottom_Board_Edge; i++) {
		GotoXY(Left_Board_Game, i);
		cout << s[i];
	}
}

void Game::Located()
{
	if (!line.empty()) {
		for (int i = 0; i < line.size(); i++) {
			line[i].Located();
		}
		line.clear();
	}
}
void Game::Run()
{
	DrawPeople();
	t = thread(&Game::ThreadFunction, this);
	char ch{};

	while (true) {
		if (!people.IsDied()) {
			ch = _getch();
			if (!(ch == UP || ch == LEFT || ch == DOWN || ch == RIGHT))
				ch = tolower(ch);
		}
		else {
			while (checkin == true);
			if (people.IsDied())
			{
				TerminateThread(t.native_handle(), 0);
				t.join();
				ClearConsole();
				return StartGame();
			}
		}
		if (ch == 'a' || ch == 'd' || ch == 's' || ch == 'w' || ch == UP || ch == LEFT || ch == DOWN || ch == RIGHT) {

			lock_guard<mutex> lock(theLock);
			UpdatePosPeople(ch);
			DrawPeople();
			if (IsLevelUp()) {
				LevelUp();
			}
		}
		else if (ch == ESC || ch == 't' || ch == 'l') {
			while (checkin == true);
			try
			{
				PauseGame(ch);
			}
			catch (string s)
			{
				if (s == "MAIN MENU") {
					Life = 3;
					return StartGame();
				}
			}
		}
		ch = ' ';
	}
}
void Game::ResumeGame()
{
	SetConsoleFontSize({ smallFontSizeW, smallFontSizeH }, L"Lucida Console");
	SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
	DrawCurrentLevel();
	DrawBoard();
	DrawPeople();
	ResumeThread(t.native_handle());
}
void Game::ResetGame()
{
	Located();
	this->Init();
}

void Game::PauseGame(char text)
{
	lock_guard<mutex> lock(theLock);
	SuspendThread(t.native_handle());
	ClearConsole();
	SetConsoleFontSize({ bigFontSizeW, bigFontSizeH }, L"Consolas");
	SetConsoleWindow(Width_Console_Menu, Height_Console_Menu);
	string select;
	char ch;
	if (text == 'l')
	{
		this->LoadGame();
		SetConsoleFontSize({ smallFontSizeW,smallFontSizeH }, L"Lucida Console");
		SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
		DrawCurrentLevel();
		DrawBoard();
		DrawPeople();
		ResumeThread(t.native_handle());
	}
	else
	{
		if (text == 't')
		{
			SaveGame();
		}
		menu.SetMenu("pause");
		while (true)
		{
			select = menu.Slection();
			menu.ClearMenu();
			if (select == "CONTINUE") {
				ResumeGame();
				break;
			}
			else if (select == "SAVE GAME")
			{
				menu.Clear();
				SaveGame();
			}
			else if (select == "LOAD GAME") {
				this->LoadGame();
				SetConsoleFontSize({ smallFontSizeW,smallFontSizeH }, L"Lucida Console");
				SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
				DrawCurrentLevel();
				DrawBoard();
				DrawPeople();
				ResumeThread(t.native_handle());
				break;
			}
			else if (select == "GUIDE") {
				menu.DrawGuide();
				do
				{
					ch = _getch();
				} while (ch != ENTER);

				ClearConsole();
			}
			else if (select == "MAIN MENU")
			{
				ClearConsole();
				MenuGame m;
				m.SetMenu("yes_no");
				SMALL_RECT rect = GetWindowSize();
				int width = rect.Right - rect.Left + 1;
				int x = (width - strlen("Back to Menu?")) / 2;
				int y = (rect.Bottom) / 3 - 5;
				GotoXY(x, y);
				cout << "Back to Menu?";
				string select = m.Slection();

				if (select == "NO") {
					string s(strlen("Back to Menu?"), ' ');
					GotoXY(x, y);
					cout << s;
				}
				else {
					TerminateThread(t.native_handle(), 0);
					t.join();
					Located();

					throw string("MAIN MENU");
				}
			}
		}
	}
}

void Game::ExitGame()
{
	ClearConsole();
	MenuGame m;
	m.SetMenu("yes_no");

	SMALL_RECT rect = GetWindowSize();
	int width = rect.Right - rect.Left + 1;
	int x = (width - strlen("Do you really wanna leave? ")) / 2;
	int y = (rect.Bottom) / 3 - 5;
	GotoXY(x, y);
	cout << "Do you really wanna leave?";

	string select = m.Slection();

	if (select == "NO") {
		string s(strlen("Do you really wanna leave?"), ' ');
		GotoXY(x, y);
		cout << s;
		return;
	}
	Located();
	quick_exit(EXIT_SUCCESS);
}

void Game::StartGame()
{
	char ch;
	string select;
	menu = MenuGame();
	SetConsoleFontSize({ bigFontSizeW, bigFontSizeH }, L"Consolas");
	SetConsoleWindow(Width_Console_Menu, Height_Console_Menu);
	ClearConsole();

	while (true)
	{
		select = menu.Slection();
		menu.ClearMenu();

		if (select == "NEW GAME") {
			SetConsoleFontSize({ smallFontSizeW,smallFontSizeH }, L"Lucida Console");
			SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
			level = LEVEL;
			DrawLevel();
			DrawBoard();
			DrawCurrentLevel();
			Init();
			return Run();
		}
		else if (select == "GUIDE") {
			menu.DrawGuide();
			do
			{
				ch = _getch();
			} while (ch != ENTER);
			ClearConsole();
		}
		else if (select == "SETTING") {
			this->SettingGame();
			ClearConsole();
		}
		else if (select == "LOAD GAME") {
			this->LoadGame();
			SetConsoleFontSize({ smallFontSizeW,smallFontSizeH }, L"Lucida Console");
			SetConsoleWindow(MaxWidth_Console + 50, MaxHeight_Console);
			DrawCurrentLevel();
			DrawBoard();
			return Run();
		}
		else if (select == "EXIT") {
			ExitGame();
		}
	}
}
void Game::LoadGame()
{
	char fileName[50];
	int num;
	string path = "Saved\\";
	vector<string> v = GetFileName("Saved");
	vector<int> lv;
	vector<tm> time_info;
	ifstream is;

	if (!v.empty()) {
		lv.resize(v.size());
		time_info.resize(v.size());

		for (int i = 0; i < v.size(); i++) {
			is.open((path + v[i]).c_str(), ios::binary);
			is.read((char*)&lv[i], sizeof(int));
			is.read((char*)&time_info[i], sizeof(tm));
			is.close();
		}
	}

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	CONSOLE_CURSOR_INFO info;

	GetConsoleScreenBufferInfo(ConsoleHandle, &csbi);
	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int x = (width - 20 - 10 - 20) / 2;
	int y = (csbi.srWindow.Bottom) / 3 - 5;


	GotoXY((width - strlen("LOAD GAME")) / 2, y - 1);
	cout << "LOAD GAME";
	GotoXY((width - strlen("Choose data")) / 2, y);
	cout << "Choose data";

	GotoXY(x, y + 4);
	printf("%-20s %-10s %-20s", "Name", "Levels", "Date");
	if (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			GotoXY(x, y + 6 + i);
			printf("%-20s %-10d %02d/%02d/%02d %02d:%02d:%02d", v[i].c_str(), lv[i],
				time_info[i].tm_mday, time_info[i].tm_mon + 1, time_info[i].tm_year + 1903,
				time_info[i].tm_hour, time_info[i].tm_min, time_info[i].tm_sec);
		}
	}
	int x_sel = x - 2;
	int y_sel = y + 6;

	GotoXY(x_sel, y_sel);
	printf("%c", 175);
	string select;

	while (true) {
		char data = _getch();
		if (!(data == UP || data == DOWN))
			data = tolower(data);
		const char ch = data;
		if (ch == 'w' || ch == UP) {
			if (y_sel > y + 6) {
				GotoXY(x_sel, y_sel);
				cout << " ";
				y_sel--;
			}
		}
		else if (ch == 's' || ch == DOWN) {
			if (y_sel < y + 6 + v.size() - 1) {
				GotoXY(x_sel, y_sel);
				cout << " ";
				y_sel++;
			}
		}
		else if (ch == ENTER) {
			path += v[y_sel - y - 6];
			break;
		}

		GotoXY(x_sel, y_sel);
		cout << (char)175;
	}

	tm tm1;
	ifstream inFile(path, ios::binary);

	inFile.read((char*)&level, sizeof(level));
	inFile.read((char*)&tm1, sizeof(tm));
	inFile.read((char*)&Life, sizeof(Life));
	inFile.read((char*)&num, sizeof(num));
	line.resize(num);

	for (int i = 0; i < num; i++) {
		line[i].Read(inFile);
	}
	people.Read(inFile);
	menu.Read(inFile);
	inFile.read((char*)&checkin, sizeof(checkin));

	inFile.close();
	ClearConsole();
}
void Game::SettingGame()
{
	ClearConsole();
	MenuGame m;
	m.SetMenu("setting");
	ClearConsole();
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	CONSOLE_CURSOR_INFO info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &csbi);
	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int x = (width - 20 - 10 - 20) / 2;
	int y = (csbi.srWindow.Bottom) / 3 - 5;
	GotoXY((width - strlen("SETTING LEVEL")) / 2, y - 1);
	cout << " SETTING LEVEL";
	GotoXY((width - strlen("Choose LEVEL")) / 2, y);
	cout << "Choose Level";
	vector<string> v;
	v.push_back("Level 1");
	v.push_back("Level 2");
	v.push_back("Level 3");
	v.push_back("Level 4");
	v.push_back("Level 5");
	if (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			GotoXY(x, y + 6 + i);
			printf("%-20s ", v[i].c_str());
		}
	}
	int x_sel = x - 2;
	int y_sel = y + 6;
	GotoXY(x_sel, y_sel);
	printf("%c", 175);
	while (true) {
		char data = _getch();
		if (!(data == UP || data == DOWN))
			data = tolower(data);
		const char ch = data;
		if (ch == 'w' || ch == UP) {
			if (y_sel > y + 6) {
				GotoXY(x_sel, y_sel);
				cout << " ";
				y_sel--;
			}
		}
		else if (ch == 's' || ch == DOWN) {
			if (y_sel < y + 6 + v.size() - 1) {
				GotoXY(x_sel, y_sel);
				cout << " ";
				y_sel++;
			}
		}
		else if (ch == ENTER) {
			int STAGE = (y_sel - y - 6) + 1;
			LEVEL = STAGE;
			break;
		}
		GotoXY(x_sel, y_sel);
		cout << (char)175;
	}
	return;

}
void Game::SaveGame()
{
	char fileName[51];
	MenuGame m;
	string path = "Saved\\";

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;

	SMALL_RECT rect = GetWindowSize();
	int width = rect.Right - rect.Left + 1;
	COORD pos;
	pos.Y = (rect.Bottom) / 3 - 4;
	pos.X = (width - strlen("File already exists! Overwrite?")) / 2;

	while (true)
	{
		GotoXY((width - strlen("Save Game")) / 2, pos.Y - 2);
		cout << "Save Game";
		GotoXY(pos.X + strlen("File already exists! Overwrite?") / 4, pos.Y);
		cout << "Input name to save: ";
		GotoXY(pos.X + strlen("File already exists! Overwrite?") / 3, pos.Y + 1);

		info.dwSize = 100;
		info.bVisible = TRUE;
		SetConsoleCursorInfo(ConsoleHandle, &info);
		cin.getline(fileName, 50);
		info.bVisible = FALSE;
		SetConsoleCursorInfo(ConsoleHandle, &info);

		path += fileName;
		if (IsExistFile(path.c_str()))
		{
			int x = (width - strlen("File already exists! Overwrite?")) / 2;
			GotoXY(x, pos.Y + 2);
			cout << "File already exists! Overwrite?";
			m.SetMenu("yes_no");
			string select = m.Slection();
			if (select == "YES") {
				m.Clear();
				break;
			}
			else {
				ClearConsole();
				path = "Saved\\";
			}
		}
		else
			break;
	}
	time_t current_time = time(0);
	tm* time_info = localtime(&current_time);

	ofstream outFile(path, ios::binary);

	outFile.write((char*)&level, sizeof(level));
	outFile.write((char*)time_info, sizeof(*time_info));
	outFile.write((char*)&Life, sizeof(Life));
	int num = line.size();
	outFile.write((char*)&num, sizeof(num));
	for (int i = 0; i < num; i++) {
		line[i].Write(outFile);
	}

	people.Write(outFile);
	menu.Write(outFile);
	outFile.write((char*)&checkin, sizeof(checkin));
	outFile.close();
	GotoXY((width - strlen("Saved!")) / 2, pos.Y + 6);
	cout << "Saved";
	GotoXY((width - strlen("Press Enter to back the Menu")) / 2, pos.Y + 7);
	cout << "Press Enter to back the Menu";

	while (_getch() != ENTER);
	ClearConsole();
}
Game::Game()
{
	level = 1;
	Life = 3;
}