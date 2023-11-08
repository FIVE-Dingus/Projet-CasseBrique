#include "colors.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

MyColor::MyColor() : MyColor(0, 255)
{
}

MyColor::MyColor(int rgb) : MyColor(rgb, 255)
{
}

MyColor::MyColor(int r, int g, int b) : MyColor(r * 0x10000 + g * 0x100 + b, 255)
{
}

MyColor::MyColor(int r, int g, int b, int a) : MyColor(r * 0x10000 + g * 0x100 + b, a)
{
}

MyColor::MyColor(int rgb, int a)
{
	setRGBA(rgb, a);
}

int MyColor::r()
{
	return _r;
}

int MyColor::g()
{
	return _g;
}

int MyColor::b()
{
	return _b;
}

int MyColor::a()
{
	return _a;
}

int MyColor::rgb()
{
	return _rgb;
}

int MyColor::rgba()
{
	return _rgba;
}

Color MyColor::getSfColor()
{
	return sf::Color(_rgba);
}

void MyColor::printColorHex(bool includeAlpha)
{
	cout << "#" << hex << (includeAlpha ? _rgba : _rgb) << dec;
}

void MyColor::printColor(bool includeAlpha)
{
	cout << "{" << _r << ", " << _g << ", " << _b;
	if (includeAlpha)
	{
		cout << ", " << _a;
	}
	cout << "} ";
}

MyColor MyColor::mixin(MyColor otherCol, float pct)
{
	MyColor mixed;
	mixin(otherCol, &mixed, pct);
	return mixed;
}

void MyColor::mixin(MyColor otherCol, MyColor* savedColor, float pct)
{
	savedColor->setRGBA(
		(otherCol.r() - _r) * pct + _r,
		(otherCol.g() - _g) * pct + _g,
		(otherCol.b() - _b) * pct + _b,
		(otherCol.a() - _a) * pct + _a
	);
}

MyColor MyColor::tripleMixin(MyColor otherCol, MyColor lastColor, float pct)
{
	MyColor mixed;
	tripleMixin(otherCol, lastColor, &mixed, pct);
	return mixed;
}

void MyColor::tripleMixin(MyColor otherCol, MyColor lastColor, MyColor* savedColor, float pct)
{
	MyColor mix1;
	MyColor mix2;
	mixin(otherCol, &mix1, pct);
	otherCol.mixin(lastColor, &mix2, pct);
	mix1.mixin(mix2, savedColor, pct);
}

void MyColor::setR(int r)
{
	setRGBA(r * 0x10000 + _g * 0x100 + _b, _a);
}

void MyColor::setG(int g)
{
	setRGBA(_r * 0x10000 + g * 0x100 + _b, _a);
}

void MyColor::setB(int b)
{
	setRGBA(_r * 0x10000 + _g * 0x100 + b, _a);
}

void MyColor::setA(int a)
{
	setRGBA(_r * 0x10000 + _g * 0x100 + _b, a);
}

void MyColor::setRGB(int rgb)
{
	setRGBA(rgb, _a);
}

void MyColor::setRGB(int r, int g, int b)
{
	setRGBA(r * 0x10000 + g * 0x100 + b, _a);
}

void MyColor::setRGBA(int rgba)
{
	setRGBA(rgba / 0x100, rgba % 0x100);
}

void MyColor::setRGBA(int r, int g, int b, int a)
{
	setRGBA(r * 0x10000 + g * 0x100 + b, a);
}

void MyColor::setRGBA(int rgb, int a)
{
	_rgb = rgb;
	_rgba = rgb * 0x100 + a;
	_a = a;
	_b = rgb % 0x100;
	_g = (rgb % 0x10000) / 0x100;
	_r = rgb / 0x10000;
}

bool MyColor::operator==(MyColor otherColor)
{
	if (_rgba == otherColor.rgba())
	{
		return true;
	}
	return false;
}

bool MyColor::operator!=(MyColor otherColor)
{
	if (_rgba == otherColor.rgba())
	{
		return !true;
	}
	return !false;
}

void MyColor::operator=(MyColor otherColor)
{
	_r = otherColor.r();
	_g = otherColor.g();
	_b = otherColor.b();
	_a = otherColor.a();
	_rgb = otherColor.rgb();
	_rgba = otherColor.rgba();
}

void MyColor::operator=(Color otherColor)
{
	_r = otherColor.r;
	_g = otherColor.g;
	_b = otherColor.b;
	_a = otherColor.a;
	_rgb = _r * 0x10000 + _g * 0x100 + _b;
	_rgba = _rgb * 0x100 + _a;
}