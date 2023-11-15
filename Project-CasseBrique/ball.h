#pragma once

#include "gameObject.h"
#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball : public GameObject
{
public:
	int mousePressed = 0;
	Ball();
	Ball(MyColor col);
	Ball(Vect2 pos, int d);
	Ball(Vect2 pos, int d, MyColor col);
	Ball(Vect2 pos, Vect2 size);
	Ball(Vect2 pos, Vect2 size, MyColor col);
	void update() override;
	void collideEnter(GameObject* otherObj) override;
};