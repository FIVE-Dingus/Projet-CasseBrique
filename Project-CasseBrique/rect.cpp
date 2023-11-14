#include "rect.h"
#include "GameObject.h"

MyRect::MyRect() : GameObject() {};
MyRect::MyRect(MyColor col) : GameObject(col) {};
MyRect::MyRect(Vect2 pos, int d) : GameObject(pos, d) {};
MyRect::MyRect(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
MyRect::MyRect(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
MyRect::MyRect(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};

void MyRect::update()
{
	this->setDirection(mousePos - this->getPos());
	this->getDirection();

	std::cout << getDirection().getAngle() << endl;
	if (-160 < getDirection().getAngle() < -10) {
		this->rotateShape(this->getDirection());
	}
}