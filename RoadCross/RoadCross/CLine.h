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
	int Height();
	void PosUpdate();
	bool IsImpact(People& people);
	void Draw();
	void Located();
	bool IsInside(const People&);
	COORD GetPos();
	void Write(ostream& outDev);
	void Read(istream& inDev);
};