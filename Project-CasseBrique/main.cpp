#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    this->newGameObjects(GameObject(Vect2(250,250), 50, MyColor(0xff0000)));
}

void Main::start()
{
    while (this->window.isOpen())
    {
        this->updateGameObject();
        this->window.drawGameObjects(this->allGameObjects);
        this->window.draw();
    }
}

void Main::updateGameObject()
{
    float deltaTime = this->clock.restart().asSeconds();
    int size = this->allGameObjects.size();
    for (int i = 0; i < size; i++)
    {
        this->allGameObjects[i].update(deltaTime * this->worldSpeed, deltaTime, this->window.getSfWindow());
    }
}

void Main::newGameObjects(GameObject obj)
{
    this->allGameObjects.resize(this->allGameObjects.size() + 1);
    this->allGameObjects[this->allGameObjects.size() -1] = obj;
}

Main::Main()
{
    this->worldSpeed = 1;
    this->initGameObjects();
    this->start();
}

int main()
{
    cout << "starting..";
    Main myMain;
    cout << "closing..";

    return 0;
}