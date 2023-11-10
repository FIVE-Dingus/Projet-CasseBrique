#pragma once

#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
public:
	float deltaTime;
	float deltaTimeWithoutTimeChange;

	Vect2 mousePos;

private:
	Vect2 pos;
	Vect2 size;
	Vect2 direction;

	Vect2 defaultSize;

	MyColor color;

	CircleShape circle;
	RectangleShape rect;
	CircleShape empty;
	bool isCircle;
	bool isEmpty;

	Vect2 subdivisionOrigin;
	Vect2 posOrigin;

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

	void setDirection(Vect2 dir);

	void setOrigin(Vect2 Origin);
	void setOrigin(Vect2 subdivision, Vect2 Origin);
	void setSubdivisionOrigin(Vect2 subdivision);

	Vect2 getPos();
	Vect2 getSize();
	Vect2 getDirection();
	Vect2 getMousePos();

	void createRect();
	void createCircle();
	void createEmpty();
	Shape* getTexture();
	void rotateShape(Vect2 direction);
	void move(RenderWindow* window);
	void update(float deltaTime, float deltaTimeWithoutTimeChange, RenderWindow* window);
	virtual void update();

private:
	void createShape();
};