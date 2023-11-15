#pragma once

#include "gameObject.h"
#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Cannon : public GameObject
{
public:
	Cannon();
	Cannon(MyColor col);
	Cannon(Vect2 pos, int d);
	Cannon(Vect2 pos, int d, MyColor col);
	Cannon(Vect2 pos, Vect2 size);
	Cannon(Vect2 pos, Vect2 size, MyColor col);
	void update() override;
};