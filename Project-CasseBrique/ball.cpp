#include "ball.h"
#include "vect.h"

Ball::Ball() : GameObject() {};
Ball::Ball(MyColor col) : GameObject(col) {};
Ball::Ball(Vect2 pos, int d) : GameObject(pos, d) {};
Ball::Ball(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
Ball::Ball(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
Ball::Ball(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};

void Ball::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousePressed++;
		this->setDirection(mousePos - this->getPos());
	}
	this->move(1);
	this->rotateShape(this->getDirection());
	if (this->collisionAABBtoCircle() == true) {
		this->setDirection(this->getPos());
	}
}