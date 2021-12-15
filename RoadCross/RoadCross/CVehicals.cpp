#include "CVehicals.h"
Vehicals::Vehicals() {}
Vehicals::Vehicals(bool theDirec) : Object(theDirec) {}
Vehicals::Vehicals(int x, int y) : Object(x, y) {}
Vehicals::Vehicals(int x, int y, bool theDirec) : Object(x, y, theDirec) {}