#include "brick.h"
#include "GameObject.h"

Brick::Brick() : GameObject() {};
Brick::Brick(MyColor col) : GameObject(col) {};
Brick::Brick(Vect2 pos, int d) : GameObject(pos, d) {};
Brick::Brick(Vect2 pos, int d, MyColor col) : GameObject(pos, d, col) {};
Brick::Brick(Vect2 pos, Vect2 size) : GameObject(pos, size) {};
Brick::Brick(Vect2 pos, Vect2 size, MyColor col) : GameObject(pos, size, col) {};

void Brick::update(){
	if (this->Life <= 0)
	{
		this->activeCollision();
		MyColor col = this->getColor();
		col.setA(0);
		this->setColor(col);
		this->Life = 1000 * 1000;
	}
}
void Brick::collideEnter(GameObject* otherObj)
{
	this->Life--;
}