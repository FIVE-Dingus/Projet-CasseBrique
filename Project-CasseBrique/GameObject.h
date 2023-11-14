#pragma once

#include "vect.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
public:
	float deltaTime;
	float deltaTimeWithoutTimeChange;

	Vect2 direction;
	CircleShape circle;
	RectangleShape rect;
	Vect2 mousePos;

private:
	Vect2 pos;
	Vect2 size;

	Vect2 defaultSize;

	MyColor color;

	CircleShape empty;
	bool isCircle;
	bool isEmpty;

	Vect2 subdivisionOrigin;
	Vect2 posOrigin;

	RenderWindow* window;

	bool isCollide;
	bool isCollideThisTurn;
	bool collisionActive;

public:
	GameObject();
	GameObject(MyColor col);
	GameObject(Vect2 pos, int d);
	GameObject(Vect2 pos, int d, MyColor col);
	GameObject(Vect2 pos, Vect2 size);
	GameObject(Vect2 pos, Vect2 size, MyColor col);

	void setWindow(RenderWindow* window);
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

	void createRect();
	void createCircle();
	void createEmpty();
	Shape* getTexture();
	void rotateShape(Vect2 direction);
	void move(float velocity);

	int getObjectType();
	bool checkCollision(GameObject* otherObj);
	void activeCollision(bool activation = false);
	bool collisionIsActive();

	void update(float deltaTime, float deltaTimeWithoutTimeChange);
	virtual void update();

	void informeCollide(bool colide, GameObject* otherObj);
	virtual void colliding(GameObject* otherObj);
	virtual void collideEnter(GameObject* otherObj);
	virtual void collideExit();


	bool collisionAABBtoAABB(GameObject* otherObj);
	bool collisionAABBtoCircle(GameObject* otherObj);
	bool collisionCircletoCircle(GameObject* otherObj);

private:
	void createShape();
};