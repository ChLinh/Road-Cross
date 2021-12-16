#pragma once
#include "CBirds.h"
Birds::Birds() {}

Birds::Birds(bool theDirec) : Animal(theDirec) {}

Birds::Birds(int x, int y) : Animal(x, y) {}

Birds::Birds(int x, int y, bool theDirec) : Animal(x, y, theDirec) {}
