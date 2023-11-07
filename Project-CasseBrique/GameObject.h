#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
private:
	int x;
	int y;
	int h;
	int w;
	CircleShape shape;

public:
	GameObject();
	GameObject(int x, int y, float d);
	GameObject(int x, int y, int w, int h);

	void createRect();
	void createCircle();
	CircleShape getTexture();

};