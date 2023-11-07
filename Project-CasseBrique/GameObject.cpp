#include "gameObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameObject::GameObject() : GameObject(0, 0, 500) {}

GameObject::GameObject(int x, int y, float d)
{
	this->x = x;
	this->y = y;
	this->w = d;
	this->h = d;
}

GameObject::GameObject(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void GameObject::createRect() {

}

void GameObject::createCircle() {
	CircleShape shape(this->w, this->h);
	shape.setFillColor(Color::Yellow);
}

CircleShape GameObject::getTexture() {
	return shape;
}