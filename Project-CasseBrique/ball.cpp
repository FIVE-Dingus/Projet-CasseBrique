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
	this->move(2);
	this->rotateShape(this->getDirection());
};

void Ball::colliding(GameObject* otherObj) {
	Vect2 dir = this->getPos() - otherObj->getPos();
	float angle = dir.getAngle();

	Vect2 offset = this->getOffsetBySubdivision();
	Vect2 mid = this->getMid();
	Vect2 topLeft(mid.x() + this->getSize().x() - offset.x(), mid.y() - offset.y());
	float miniAngle = (180 - (topLeft - mid).getAngle()) * 2;
	float maxiAngle = 180 - miniAngle;
	miniAngle /= 2;

	if ((miniAngle <= angle && angle <= miniAngle + maxiAngle) || (-miniAngle >= angle && angle >= -(miniAngle + maxiAngle))) {
		dir.setY(dir.y() * -1);
		this->setDirection(dir);
	}
	else
	{
		dir.setY(dir.x() * -1);
		this->setDirection(dir);
	}
};