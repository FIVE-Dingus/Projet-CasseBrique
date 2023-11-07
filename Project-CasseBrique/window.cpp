#include "window.h"
#include <SFML/Graphics.hpp>
using namespace sf;

MyWindow::MyWindow() : MyWindow(0, 0, true) {};

MyWindow::MyWindow(int x, int y, bool lockedSize)
{
	this->setParams(x, y, lockedSize);
}

bool MyWindow::isOpen()
{
	return this->renderWindow.isOpen();
}

void MyWindow::setParams(int x, int y, bool lockedSize)
{
	this->sizeX = x;
	this->sizeY = y;
	this->lockedSize = lockedSize;

	this->renderWindow.setSize(Vector2u(this->sizeX, this->sizeY));

	this->renderWindow.pollEvent(this->event);
}

void MyWindow::drawGameObjects(vector<GameObject> gameObject)
{
	int size = gameObject.size();
	for (int i = 0; i < size; i++)
	{
		this->drawGameObject(gameObjects[i]);
	}
}

void MyWindow::drawGameObject(GameObject gameObject)
{
	int size = gameObjects.size();
	gameObjects.resize(size + 1);
	gameObjects[size + 1] = gameObject;
}

void MyWindow::draw()
{
	while (this->renderWindow.pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->renderWindow.close();
	}

	if (lockedSize)
	{
		renderWindow.setSize(Vector2u(sizeX, sizeY));
	}

	renderWindow.clear();

	int size = gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		gameObjects[i].getTexture();
	}

	renderWindow.display();
}
