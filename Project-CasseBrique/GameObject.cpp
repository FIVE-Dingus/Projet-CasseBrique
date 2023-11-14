#include "gameObject.h"
#include "maths.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"
using namespace sf;
using namespace std;
using namespace Maths;

GameObject::GameObject()
{
	this->collisionActive = true;
	this->subdivisionOrigin = { 2, 2 };
	this->posOrigin = { 1, 1 };
	this->defaultSize = { 1, 1 };
	this->setPosition(pos);
	this->setSize(size);
	this->createEmpty();
}

GameObject::GameObject(MyColor col) : GameObject()
{
	this->setColor(col);
}

GameObject::GameObject(Vect2 pos, int d)
{
	this->collisionActive = true;
	this->subdivisionOrigin = { 2, 2 };
	this->posOrigin = { 1, 1 };
	this->defaultSize = { 1, 1 };
	this->setPosition(pos);
	this->setSize(Vect2(d, d));
	this->createCircle();
}

GameObject::GameObject(Vect2 pos, int d, MyColor col) : GameObject(pos, d)
{
	this->setColor(col);
}

GameObject::GameObject(Vect2 pos, Vect2 size)
{
	this->collisionActive = true;
	this->subdivisionOrigin = { 2, 2 };
	this->posOrigin = { 1, 1 };
	this->defaultSize = { 1, 1 };
	this->setPosition(pos);
	this->setSize(size);
	this->createRect();
}

GameObject::GameObject(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size)
{
	this->setColor(col);
}

void GameObject::setWindow(RenderWindow* window) {
	this->window = window;
}

void GameObject::setPosition(Vect2 pos)
{
	this->circle.setOrigin({ this->size.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->size.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });
	this->rect.setOrigin({ this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });

	this->pos = pos;
	this->circle.setPosition(this->pos.x(), this->pos.y());
	this->rect.setPosition(this->pos.x(), this->pos.y());
}

void GameObject::setSize(int d)
{
	this->circle.setOrigin({ this->size.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->size.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });
	this->rect.setOrigin({ this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });

	this->size = Vect2(d /2, d /2);
	this->circle.setRadius(this->size.x() /2);
	this->circle.setPointCount(this->size.y() /2);
	this->rect.setScale(this->size.x() / this->defaultSize.x(), this->size.y() / this->defaultSize.y());
}

void GameObject::setSize(Vect2 size)
{
	this->circle.setOrigin({ this->size.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->size.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });
	this->rect.setOrigin({ this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) });

	this->size = size;
	this->circle.setRadius(this->size.x() /2);
	this->circle.setPointCount(this->size.y() /2);
	this->rect.setScale(this->size.x() / this->defaultSize.x(), this->size.y() / this->defaultSize.y());
}

void GameObject::setColor(MyColor color)
{
	this->color = color;
	this->circle.setFillColor(color.getSfColor());
	this->rect.setFillColor(color.getSfColor());
}

void GameObject::setDirection(Vect2 dir)
{
	//dir.normalize();
	this->direction = dir;
}

void GameObject::setOrigin(Vect2 Origin)
{
	Vect2 offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos -= offset;
	this->posOrigin = Origin;
	offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos += offset;
	this->createShape();
}

void GameObject::setOrigin(Vect2 subdivision, Vect2 Origin)
{
	Vect2 offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos -= offset;
	this->posOrigin = Origin;
	this->subdivisionOrigin = subdivision;
	offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos += offset;
	this->createShape();
}

void GameObject::setSubdivisionOrigin(Vect2 subdivision)
{
	Vect2 offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos -= offset;
	this->subdivisionOrigin = subdivision;
	offset = { this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y()) };
	this->pos += offset;
	this->createShape();
}

Vect2 GameObject::getPos()
{
	return this->pos;
}

Vect2 GameObject::getSize()
{
	return this->size;
}

Vect2 GameObject::getDirection()
{
	return this->direction;
}

void GameObject::createRect()
{
	this->isEmpty = false;
	this->isCircle = false;
	this->rect = RectangleShape(this->defaultSize.getVector2f());
	this->createShape();
}

void GameObject::createCircle()
{
	this->isEmpty = false;
	this->isCircle = true;
	this->circle = CircleShape(this->size.x() /2);
	this->createShape();
}

void GameObject::createEmpty()
{
	this->isEmpty = true;
	this->isCircle = false;
	this->empty = CircleShape();
	this->createShape();
}

void GameObject::createShape()
{
	this->circle.setOrigin({this->size.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->size.y() * (this->posOrigin.y() / this->subdivisionOrigin.y())});
	this->rect.setOrigin({this->defaultSize.x() * (this->posOrigin.x() / this->subdivisionOrigin.x()), this->defaultSize.y() * (this->posOrigin.y() / this->subdivisionOrigin.y())});

	this->circle.setPosition(this->pos.x(), this->pos.y());
	this->circle.setRadius(this->size.x() /2);
	this->circle.setFillColor(this->color.getSfColor());

	this->rect.setPosition(this->pos.x(), this->pos.y());
	this->rect.setScale(this->size.x() / this->defaultSize.x(), this->size.y() / this->defaultSize.y());
	this->rect.setFillColor(this->color.getSfColor());

	this->empty.setPosition(0, 0);
	this->empty.setScale(0, 0);
	this->empty.setFillColor(MyColor(0, 0).getSfColor());
}

Shape* GameObject::getTexture()
{
	switch (getObjectType())
	{
	case 0:
		return &empty;
	case 1:
		return &rect;
	case 2:
		return &circle;

	default:
		return &empty;
	}
}

void GameObject::rotateShape(Vect2 direction) {
	//this->circle.setRotation(direction.getAngle());
	this->rect.setRotation(direction.getAngle());
}

void GameObject::move(float velocity) {
	Vect2 movement = direction * velocity * this->deltaTime * 100;
	this->setPosition(pos + movement);
}

void GameObject::update(float deltaTime, float deltaTimeWithoutTimeChange)
{
	this->isCollideThisTurn = false;
	this->deltaTime = deltaTime;
	this->deltaTimeWithoutTimeChange = deltaTimeWithoutTimeChange;
	Vector2i position = Mouse::getPosition(*window);
	this->mousePos = { position.x * 1.f , position.y * 1.f };
	this->update();
}

int GameObject::getObjectType()
{
	if (this->isEmpty)
	{
		return 0;
	}
	if (this->isCircle)
	{
		return 2;
	}
	return 1;
}

bool GameObject::checkCollision(GameObject* otherObj)
{
	int type1 = getObjectType();
	int type2 = otherObj->getObjectType();
	if (!this->collisionActive || !otherObj->collisionIsActive())
	{
		return false;
	}
	else if (type1 == 0 || type2 == 0)
	{
		return false;
	}
	else if (type1 == 1 && type2 == 1)
	{
		return collisionAABBtoAABB(otherObj);
	}
	else if (type1 == 2 && type2 == 2)
	{
		return collisionCircletoCircle(otherObj);
	}
	else if (type1 == 1 && type2 == 2)
	{
		return collisionAABBtoCircle(otherObj);
	}
	else if (type1 == 2 && type2 == 1)
	{
		return otherObj->collisionAABBtoCircle(this);
	}
}

void GameObject::activeCollision(bool activation)
{
	this->collisionActive = activation;
}

bool GameObject::collisionIsActive()
{
	return this->collisionActive;
}

bool GameObject::collisionAABBtoAABB(GameObject* otherObj)
{
	Vect2 tempPos;
	Vect2 pos1_x = { pos.x(), pos.x() + size.x() };
	Vect2 pos2_x = { otherObj->getPos().x(), otherObj->getPos().x() + otherObj->getSize().x() };
	Vect2 pos1_y = { pos.y(), pos.y() + size.y() };
	Vect2 pos2_y = { otherObj->getPos().y(), otherObj->getPos().y() + otherObj->getSize().y() };

	if (abs(pos1_x.y() - pos1_x.x()) > abs(pos2_x.y() - pos2_x.x()))
	{
		tempPos = pos2_x;
		pos2_x = pos1_x;
		pos1_x = tempPos;
	}

	if (abs(pos1_y.y() - pos1_y.x()) > abs(pos2_y.y() - pos2_y.x()))
	{
		tempPos = pos2_y;
		pos2_y = pos1_y;
		pos1_y = tempPos;
	}

	if (!isBeetwen(pos1_x.x(), pos2_x.x(), pos2_x.y()) && !isBeetwen(pos1_x.y(), pos2_x.x(), pos2_x.y()))
	{
		return false;
	}

	if (!isBeetwen(pos1_y.x(), pos2_y.x(), pos2_y.y()) && !isBeetwen(pos1_y.y(), pos2_y.x(), pos2_y.y()))
	{
		return false;
	}

	return true;
}

bool GameObject::collisionAABBtoCircle(GameObject* otherObj)
{
	int minDist = otherObj->getSize().x() / 2;
	int dist = (this->pos - otherObj->getPos()).norme();
	if (minDist >= dist)
	{
		return true;
	}

	Vect2 dir = (this->pos - otherObj->getPos()).normal() * (otherObj->getSize().x() / 2);
	Vect2 pointToTest = otherObj->getPos() + dir;
	Vect2 offset(this->size.x() / subdivisionOrigin.x() * posOrigin.x(), this->size.y() / subdivisionOrigin.y() * posOrigin.y());
	Vect2 topLeft(this->pos.x() + this->size.x() - offset.x(), this->pos.y() - offset.y());
	Vect2 botRight(this->pos.x() - offset.x(), this->pos.y() + this->size.y() - offset.y());

	if (isBeetwen(pointToTest.x(), topLeft.x(), botRight.x()) && isBeetwen(pointToTest.y(), topLeft.y(), botRight.y()))
	{
		return true;
	}
	return false;
}

bool GameObject::collisionCircletoCircle(GameObject* otherObj)
{
	int minDist = this->size.x() / 2 + otherObj->getSize().x() / 2;
	int dist = (this->pos - otherObj->getPos()).norme();
	return minDist >= dist;
}

void GameObject::informeCollide(bool colide, GameObject* otherObj)
{
	if (!this->isCollide && colide)
	{
		this->isCollideThisTurn = true;
		this->isCollide = true;
		this->collideEnter(otherObj);
		this->colliding(otherObj);
	}
	else if (this->isCollide && !colide && !this->isCollideThisTurn)
	{
		this->isCollide = false;
		this->collideExit();
	}
	else if (this->isCollide && colide)
	{
		this->isCollideThisTurn = true;
		this->colliding(otherObj);
	}
}

void GameObject::update() {}
void GameObject::colliding(GameObject* otherObj) {

}
void GameObject::collideEnter(GameObject* otherObj) {
	this->circle.setFillColor(MyColor(0xff0000, 50).getSfColor());
	this->rect.setFillColor(MyColor(0xff0000, 50).getSfColor());
}

void GameObject::collideExit() {
	this->circle.setFillColor(this->color.getSfColor());
	this->rect.setFillColor(this->color.getSfColor());
}