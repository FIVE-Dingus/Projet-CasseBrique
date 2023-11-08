#include "gameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

GameObject::GameObject() : GameObject(Vect2(0), 500) {}

GameObject::GameObject(MyColor col) : GameObject(Vect2(0), 500, col) {}

GameObject::GameObject(Vect2 pos, int d) : GameObject(pos, Vect2(d /2, d /2)) {}

GameObject::GameObject(Vect2 pos, int d, MyColor col) : GameObject(pos, Vect2(d /2, d /2), col) {}

GameObject::GameObject(Vect2 pos, Vect2 size)
{
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
	this->shape->setPosition(this->pos.x(), this->pos.y());
}

void GameObject::setSize(int d)
{
	this->size = Vect2(d /2, d /2);
	this->shape->setRadius(this->size.x());
	this->shape->setPointCount(this->size.y());
}

void GameObject::setSize(Vect2 size)
{
	this->size = size;
	this->shape->setRadius(this->size.x());
	this->shape->setPointCount(this->size.y());
}

void GameObject::setColor(MyColor color)
{
	this->color = color;
	this->shape->setFillColor(color.getSfColor());
}

void GameObject::createRect()
{

}

void GameObject::createCircle()
{
	this->shape[0] = CircleShape(this->size.x(), this->size.y());
	this->createShape();
}

void GameObject::createShape()
{
	this->shape->setPosition(this->pos.x(), this->pos.y());
	this->shape->setRadius(this->size.x());
	this->shape->setPointCount(this->size.y());
	this->shape->setFillColor(this->color.getSfColor());
}

Shape* GameObject::getTexture()
{
	return shape;
}