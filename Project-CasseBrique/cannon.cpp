#include "cannon.h"
#include "GameObject.h"

Cannon::Cannon() : GameObject() {};
Cannon::Cannon(MyColor col) : GameObject(col) {};
Cannon::Cannon(Vect2 pos, int d) : GameObject(pos, d) {};
Cannon::Cannon(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
Cannon::Cannon(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
Cannon::Cannon(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};

void Cannon::update()
{
	this->setDirection(mousePos - this->getPos());
	if (-160 < getDirection().getAngle() && getDirection().getAngle() < -10) {
		this->rotateShape(this->getDirection());
	}
}