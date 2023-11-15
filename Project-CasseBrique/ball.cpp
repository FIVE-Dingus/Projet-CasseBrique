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


void Ball::collideEnter(GameObject* otherObj){
	Vect2 dir = getDirection();
	if (dir.y() < 0 && abs(dir.y()) > abs(dir.x())) {
		dir.setY(dir.y() * -1);
		this->setDirection(dir);
	} else if (dir.y() > 0 && abs(dir.y()) > abs(dir.x())) {
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