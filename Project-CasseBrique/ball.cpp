#include "ball.h"

Ball::Ball() : GameObject() {};
Ball::Ball(MyColor col) : GameObject(col) {};
Ball::Ball(Vect2 pos, int d) : GameObject(pos, d) {};
Ball::Ball(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
Ball::Ball(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
Ball::Ball(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};

void Ball::update()
{
	this->setDirection(mousePos - this->getPos());
	this->rotateShape(this->getDirection());
	this->move(0.02);

}