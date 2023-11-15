#pragma once

#include "gameObject.h"
#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Brick : public GameObject
{
private:
	int Life = 2;

public:
	Brick();
	Brick(MyColor col);
	Brick(Vect2 pos, int d);
	Brick(Vect2 pos, int d, MyColor col);
	Brick(Vect2 pos, Vect2 size);
	Brick(Vect2 pos, Vect2 size, MyColor col);
	void update() override;
	void collideEnter(GameObject* otherObj) override;
};