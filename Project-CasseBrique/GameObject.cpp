#include "gameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

GameObject::GameObject()
{
	this->defaultSize = { 1, 1 };
	this->createEmpty();
	this->setPosition(pos);
	this->setSize(size);
}

GameObject::GameObject(MyColor col) : GameObject()
{
	this->setColor(col);
}

GameObject::GameObject(Vect2 pos, int d)
{
	this->defaultSize = { 1, 1 };
	this->createCircle();
	this->setPosition(pos);
	this->setSize(size);
}

GameObject::GameObject(Vect2 pos, int d, MyColor col) : GameObject(pos, d)
{
	this->setColor(col);
}

GameObject::GameObject(Vect2 pos, Vect2 size)
{
	this->defaultSize = { 1, 1 };
	this->createRect();
	this->setPosition(pos);
	this->setSize(size);
}

GameObject::GameObject(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size)
{
	this->setColor(col);
}

void GameObject::setPosition(Vect2 pos)
{
	this->pos = pos;
	this->circle.setPosition(this->pos.x(), this->pos.y());
	this->rect.setPosition(this->pos.x(), this->pos.y());
}

void GameObject::setSize(int d)
{
	this->size = Vect2(d /2, d /2);
	this->circle.setRadius(this->size.x() /2);
	this->circle.setPointCount(this->size.y());
	this->rect.setScale(this->size.x() / this->defaultSize.x(), this->size.y() / this->defaultSize.y());
}

void GameObject::setSize(Vect2 size)
{
	this->size = size;
	this->circle.setRadius(this->size.x() /2);
	this->circle.setPointCount(this->size.y());
	this->rect.setScale(this->size.x() / this->defaultSize.x(), this->size.y() / this->defaultSize.y());
}

void GameObject::setColor(MyColor color)
{
	this->color = color;
	this->circle.setFillColor(color.getSfColor());
	this->rect.setFillColor(color.getSfColor());
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
	this->circle = CircleShape(this->size.x(), this->size.y());
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
	this->circle.setPosition(this->pos.x(), this->pos.y());
	this->circle.setRadius(this->size.x() /2);
	this->circle.setPointCount(this->size.y());
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
	if (this->isEmpty)
	{
		return &empty;
	}
	if (this->isCircle)
	{
		return &circle;
	}
	return &rect;
}

void GameObject::rotateShape(Vect2 direction) {
	this->circle.rotate(direction.getAngle());
}

void GameObject::update()
{

}

void GameObject::updateGraphic()
{

}