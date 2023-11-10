#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    MyColor col1;
    MyColor col2;
    col1.setHSV(360100100);
    col1.setHSV(000100100);
    MyColor mixed;
    float pct = 0.f;
    for (int i = 0; i < 500; i++)
    {
        pct = i / 500.f;
        col1.HSVmixin(col2, &mixed, pct);
        this->newGameObjects(GameObject(Vect2(i, 0), Vect2(1, 500), mixed));
        this->allGameObjects[i].setOrigin({0, 0});
    }
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