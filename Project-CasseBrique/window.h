#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameObject.h"
using namespace sf;
using namespace std;

class MyWindow
{
private:
	int sizeX;
	int sizeY;
	bool lockedSize;
	Event event;
	RenderWindow renderWindow;
	vector<GameObject> gameObjects;

public:
	MyWindow();
	MyWindow(int x, int y, bool lockedSize = true);
	bool isOpen();

	void setParams(int x, int y, bool lockedSize = true);
	void drawGameObjects(vector<GameObject> gameObject);
	void drawGameObject(GameObject gameObject);
	void draw();
};