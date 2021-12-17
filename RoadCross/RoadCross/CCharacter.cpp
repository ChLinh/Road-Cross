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