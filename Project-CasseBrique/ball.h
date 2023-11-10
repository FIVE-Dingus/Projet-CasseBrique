#pragma once
#include "gameObject.h"

class Ball : public GameObject
{
public:
	Ball(Vect2 pos, int d, MyColor col);
	void update() override;
};