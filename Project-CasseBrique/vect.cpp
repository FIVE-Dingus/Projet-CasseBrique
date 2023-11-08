#include "vect.h"
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace sf;

Vect2::Vect2() : Vect2(0, 0, false)
{
}

Vect2::Vect2(bool abs) : Vect2(0, 0, abs)
{
}

Vect2::Vect2(int x, int y) : Vect2(x, y, false)
{
}

Vect2::Vect2(int x, int y, bool abs)
{
	_x = x;
	_y = y;
	setIfOnlyInAbs(abs);
	makeAbsolute();
}

void Vect2::setIfOnlyInAbs(bool abs)
{
	abs = abs;
}

int Vect2::x()
{
	return _x;
}

int Vect2::y()
{
	return _y;
}

int Vect2::norme()
{
	return sqrt((_x * _x) + (_y * _y));
}

Vect2 Vect2::normal()
{
	Vect2 newVect2(_x / norme(), _y / norme());
	return newVect2;
}

void Vect2::normalize()
{
	_x = _x / norme();
	_y = _y / norme();
	makeAbsolute();
}

float Vect2::getAngle() {

	float angle = acos(_x / norme());
	return angle;
}

Vector2u Vect2::getVector2u()
{
	return Vector2u(_x, _y);
}

Vector2f Vect2::getVector2f()
{
	return Vector2f(_x, _y);
}

VideoMode Vect2::getVideoMode()
{
	return VideoMode(_x, _y);
}

Vect2 Vect2::operator*(int val)
{
	Vect2 newVect2(_x * val, _y * val);
	return newVect2;
}

Vect2 Vect2::operator/(int val)
{
	Vect2 newVect2(_x / val, _y / val);
	return newVect2;
}

int Vect2::operator*(Vect2 otherVect2)
{
	return (_x * otherVect2.x()) + (_y * otherVect2.y());
}

Vect2 Vect2::operator+(Vect2 otherVect2)
{
	Vect2 newVect2(_x + otherVect2.x(), _y + otherVect2.y());
	return newVect2;
}

Vect2 Vect2::operator-(Vect2 otherVect2)
{
	Vect2 newVect2(_x - otherVect2.x(), _y - otherVect2.y());
	return newVect2;
}

void Vect2::operator=(Vect2 otherVect2)
{
	_x = otherVect2.x();
	_y = otherVect2.y();
	makeAbsolute();
}

void Vect2::operator*=(int val)
{
	_x = _x * val;
	_y = _y * val;
	makeAbsolute();
}

void Vect2::operator/=(int val)
{
	_x = _x / val;
	_y = _y / val;
	makeAbsolute();
}

void Vect2::operator+=(Vect2 otherVect2)
{
	_x = _x + otherVect2.x();
	_y = _y + otherVect2.y();
	makeAbsolute();
}

void Vect2::operator-=(Vect2 otherVect2)
{
	_x = _x - otherVect2.x();
	_y = _y - otherVect2.y();
	makeAbsolute();
}

void Vect2::makeAbsolute()
{
	if (abs)
	{
		if (_x < 0)
		{
			_x = 0;
		}
		if (_y < 0)
		{
			_y = 0;
		}
	}
}