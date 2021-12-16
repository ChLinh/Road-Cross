#pragma once
#include "CDinosaurs.h"
Dinosaurs::Dinosaurs() {}

Dinosaurs::Dinosaurs(bool theDirec) : Animal(theDirec) {}

Dinosaurs::Dinosaurs(int x, int y) : Animal(x, y) {}

Dinosaurs::Dinosaurs(int x, int y, bool theDirec) : Animal(x, y, theDirec) {}

