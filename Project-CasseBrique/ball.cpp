#include "ball.h"
#include "vect.h"
#include "main.h"

Ball::Ball() : GameObject() {};
Ball::Ball(MyColor col) : GameObject(col) {};
Ball::Ball(Vect2 pos, int d) : GameObject(pos, d) {};
Ball::Ball(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
Ball::Ball(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
Ball::Ball(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};


void Ball::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePressed == 0)
	{
		mousePressed++;
		Vect2 dir = this->getPos() - mousePos;
		dir.setX(dir.x() * -1);
		this->setDirection( dir );
	}
	this->move(2);
	this->rotateShape(this->getDirection());
};

//void Ball::colliding(GameObject* otherObj) {
//	Vect2 dir = this->getPos() - otherObj->getPos();
//	float angle = dir.getAngle();
//
//	Vect2 offset = this->getOffsetBySubdivision();
//	Vect2 mid = this->getMid();
//	Vect2 topLeft(mid.x() + this->getSize().x() - offset.x(), mid.y() - offset.y());
//	float miniAngle = (180 - (topLeft - mid).getAngle()) * 2;
//	float maxiAngle = 180 - miniAngle;
//	miniAngle /= 2;
//
//	if ((miniAngle <= angle && angle <= miniAngle + maxiAngle) || (-miniAngle >= angle && angle >= -(miniAngle + maxiAngle))) {
//		dir.setY(dir.y() * -1);
//		this->setDirection(dir);
//	}
//	else
//	{
//		dir.setY(dir.x() * -1);
//		this->setDirection(dir);
//	}
//};
 
void Ball::collideEnter(GameObject* otherObj) {
	Vect2 dir = getDirection();
	if (dir.y() < 0 && abs(dir.y()) > abs(dir.x())) {
		dir.setY(dir.y() * -1);
		this->setDirection(dir);
	}
	else if (dir.y() > 0 && abs(dir.y()) > abs(dir.x())) {
		dir.setY(dir.y() * -1);
		this->setDirection(dir);
	}
	if (dir.x() < 0 && abs(dir.x()) > abs(dir.y())) {
		dir.setY(dir.x() * -1);
		this->setDirection(dir);
	}
	else if (dir.x() > 0 && abs(dir.x()) > abs(dir.y())) {
		dir.setY(dir.x() * -1);
		this->setDirection(dir);
	}
};