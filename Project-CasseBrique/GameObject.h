#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
private:
	int x;
	int y;
	int h;
	int w;
	float d;
	CircleShape shape;

public:
	GameObject(int x, int y, int w, int h);

	void createRect(int w, int h);
	void createCircle(float d);
	CircleShape getTexture();

};