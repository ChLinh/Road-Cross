#include "CCharacter.h"
#define MAX 1024


Character::Character(){}

Character::~Character(){}

int Character::Width()
{
	return width;
}
int Character::Height()
{
	return height;
}
vector<string>& Character::Get()
{
	return str;
}
void Character::Draw(int x, int y, bool shap)
{
	if (shap)
	{
		if (x > Left_Board_Game)
		{
			if (x + width - 1 < Right_Board_Game)
			{
				for (int i = 0; i < height; i++) {
					GotoXY(x, y + i);
					cout<< str[i].c_str();
				}
			}
			else
			{
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < Right_Board_Game - x; j++)
					{
						GotoXY(x + j, i + y);
						cout << str[i].c_str()[j];
					}
				}
			}
		}
		else
		{
			int index = Left_Board_Game - x + 1;
			for (int i = 0; i < height; i++)
			{
				GotoXY(Left_Board_Game + 1, y + i);
				cout << str[i].c_str() + index;
			}
		}
	}
	else
	{
		for (int i = 0; i < height; i++)
		{
			GotoXY(x, y + i);
			cout << str[i].c_str();

		}
	}
}


Character::Character(const char* filename)
{
	ifstream fin(filename);
	width = height = 0;
	char buf[MAX + 1];
	while (!fin.eof())
	{
		fin.getline(buf, MAX);
		str.push_back(string(buf));
		height++;
	}
	width = str[0].length();
}

void Character::Set(const char* name)
{
	if (!str.empty())
	{
		str.clear();
	}
	ifstream fin(name);
	width = height = 0;
	char buf[MAX + 1];
	while (!fin.eof())
	{
		fin.getline(buf, MAX);
		str.push_back(string(buf));
		height++;
	}
	width = str[0].length();
}
Character Character::operator+(Character& cha)
{
	if (height != cha.height) {
		return *this;
	}

	Character Character;

	for (int i = 0; i < height; i++) {
		Character.str.push_back(str[i] + cha.str[i]);
	}

	Character.width = width + cha.width;
	Character.height = height;

	return Character;
}
void Character::Write(ostream& out)
{
	out.write((char*)&width, sizeof(width));
	out.write((char*)&height, sizeof(height));
	for (int i = 0; i < height; i++)
	{
		int length = str[i].length();
		out.write((char*)&length, sizeof(length));
		out.write(str[i].c_str(), sizeof(char) * length);

	}
}
void Character::Read(istream& in)
{
	in.read((char*)&width, sizeof(width));
	in.read((char*)&height, sizeof(height));

	str.resize(height);
	int length;

	for (int i = 0; i < height; i++) {
		in.read((char*)&length, sizeof(length));
		str[i].resize(length);
		in.read((char*)&str[i][0], sizeof(char) * length);
	}
}