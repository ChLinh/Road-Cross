#pragma once
#include"CObject.h"
class Animal abstract : public Object
{
public:
	Animal();
	Animal(bool);
	Animal(int, int);
	Animal(int, int, bool);
};