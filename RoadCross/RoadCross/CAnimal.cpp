#include "CAnimal.h"
Animal::Animal() {}
Animal::Animal(int x, int y) :Object(x, y)
{
}
Animal::Animal(int x, int y, bool dir) : Object(x, y, dir)
{
}
Animal::Animal(bool dir) : Object(dir)
{
}
