#pragma once
#include"CPeople.h"
#include"CObject.h"
#include"CBirds.h"
#include"CDinosaurs.h"
#include"CTrucks.h"
#include"CStopLight.h"
#include"CCars.h"
class Line {
public:
	int width, height;
	COORD pos;
	vector<Object*> obj;
	StopLight* stop;
	bool dir;
	short sleep;
	short timeCount;
public:
	Line();
	Line(COORD, vector<Object*>, bool, short);
	~Line() {}
	void Located();
	bool IsInside(const People&);
	COORD GetPos();
};