#pragma once

#include "gameObject.h"
#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class MyRect : public GameObject
{
public:
	MyRect();
	MyRect(MyColor col);
	MyRect(Vect2 pos, int d);
	MyRect(Vect2 pos, int d, MyColor col);
	MyRect(Vect2 pos, Vect2 size);
	MyRect(Vect2 pos, Vect2 size, MyColor col);
	void update() override;
};