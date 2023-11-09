#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    this->newGameObjects(GameObject(Vect2(100, 100), 100, MyColor(0x00ff00)));
    this->newGameObjects(GameObject(Vect2(50, 50), Vect2(100, 100), MyColor(0x000000, 127)));
    this->newGameObjects(GameObject(Vect2(150, 150), Vect2(100, 100), MyColor(0x000000, 127)));
}

void Main::start()
{
    while (this->window.isOpen())
    {
        this->window.drawGameObjects(this->allGameObjects);
        this->window.draw();
    }
}

void Main::updateGameObject()
{
    float deltaTime = this->clock.restart().asMilliseconds();
    int size = this->allGameObjects.size();
    for (int i = 0; i < size; i++)
    {
        this->allGameObjects[i].update(deltaTime * this->worldSpeed, deltaTime);
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