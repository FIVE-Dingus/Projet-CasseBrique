#pragma once

#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
private:
	Vect2 pos;
	Vect2 defaultSize;
	Vect2 size;

	MyColor color;

	Shape* shape;

public:
	GameObject();
	GameObject(MyColor col);
	GameObject(Vect2 pos, int d);
	GameObject(Vect2 pos, int d, MyColor col);
	GameObject(Vect2 pos, Vect2 size);
	GameObject(Vect2 pos, Vect2 size, MyColor col);

	void setPosition(Vect2 pos);
	void setSize(int d);
	void setSize(Vect2 size);
	void setColor(MyColor color);

	void createRect();
	void createCircle();
	Shape* getTexture();

private:
	void createShape();
};