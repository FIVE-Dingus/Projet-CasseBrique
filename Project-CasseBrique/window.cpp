#include "window.h"
#include "vect.h"
#include <SFML/Graphics.hpp>
using namespace sf;

MyWindow::MyWindow() : MyWindow(Vect2(500, 500), true) {}

MyWindow::MyWindow(Vect2 size, bool lockedSize)
{
	this->setParams(size, lockedSize);
}

bool MyWindow::isOpen()
{
	return this->renderWindow.isOpen();
}

void MyWindow::setParams(Vect2 size, bool lockedSize)
{
	this->size = size;
	this->lockedSize = lockedSize;

	if (this->isOpen())
	{
		this->renderWindow.close();
	}
	settings.antialiasingLevel = 16;
	this->renderWindow.create(this->size.getVideoMode(), "SFML works!", Style::Default, settings);

	this->renderWindow.pollEvent(this->event);
}

void MyWindow::drawGameObjects(vector<GameObject> gameObject)
{
	int size = gameObject.size();
	for (int i = 0; i < size; i++)
	{
		this->drawGameObject(gameObject[i]);
	}
}

void MyWindow::drawGameObject(GameObject gameObject)
{
	int size = gameObjects.size();
	gameObjects.resize(size + 1);
	gameObjects[size] = gameObject;
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
		renderWindow.setSize(this->size.getVector2u());
	}

	renderWindow.clear();

	int size = gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		renderWindow.draw(*gameObjects[i].getTexture());
	}

	renderWindow.display();

	gameObjects.resize(0);
}
