#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameObject.h"
#include "vect.h"
using namespace sf;
using namespace std;

class MyWindow
{
private:
	Vect2 size;
	bool lockedSize;
	Event event;
	RenderWindow renderWindow;
	vector<GameObject> gameObjects;

public:
	MyWindow();
	MyWindow(Vect2 size, bool lockedSize = true);
	bool isOpen();

	void drawGameObjects(vector<GameObject> gameObject);
	void drawGameObject(GameObject gameObject);
	void draw();

private:
	void setParams(Vect2 size, bool lockedSize = true);
};