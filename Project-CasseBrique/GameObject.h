#pragma once

#include "vect.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
private:
	Vect2 pos;
	Vect2 size;

	CircleShape shape;

public:
	GameObject();
	GameObject(Vect2 pos, int d);
	GameObject(Vect2 pos, Vect2 size);

	void createRect();
	void createCircle();
	CircleShape getTexture();

};