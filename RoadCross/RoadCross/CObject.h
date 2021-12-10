#pragma once
class Object abstract
{
private:
	int X, Y;
protected:
	int preX;
	bool dir;//1: left,0: right
public:
	Object();
	Object(bool);
	Object(int, int, bool dirs = 1);
	~Object() {}
};

