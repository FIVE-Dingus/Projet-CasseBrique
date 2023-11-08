#include "gameObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameObject::GameObject() : GameObject(Vect2(0), 500) {}

GameObject::GameObject(Vect2 pos, int d) : GameObject(pos, Vect2(d, d)) {}

GameObject::GameObject(Vect2 pos, Vect2 size)
{
	this->pos = pos;
	this->size = size;
}

void GameObject::createRect()
{

}

void GameObject::createCircle()
{
	this->shape = CircleShape(this->size.x() /2, this->size.y() /2);
	shape.setPosition(this->pos.x(), this->pos.y());
	shape.setFillColor(Color::Yellow);
}

CircleShape GameObject::getTexture()
{
	return shape;
}