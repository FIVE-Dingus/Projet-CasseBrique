#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "ball.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    this->newGameObjects(new Ball(Vect2(100, 100), 100, MyColor(0x00ff00)));
    this->newGameObjects(new Ball(Vect2(100, 100), Vect2(60, 20), MyColor(0x000000, 100)));
    this->allGameObjects[1]->setOrigin({ 0, 1 });
    this->newGameObjects(new GameObject(Vect2(300, 300), Vect2(60, 60), MyColor(0x0000ff)));
    this->newGameObjects(new GameObject(Vect2(100, 300), 60, MyColor(0x0000ff)));
}

void Main::start()
{
    while (this->window.isOpen())
    {
        this->updateGameObject();
        this->checkCollides();
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
        this->allGameObjects[i]->update(deltaTime * this->worldSpeed, deltaTime);
    }
}

void Main::newGameObjects(GameObject* obj)
{
    this->allGameObjects.resize(this->allGameObjects.size() + 1);
    obj->setWindow(this->window.getSfWindow());
    this->allGameObjects[this->allGameObjects.size() - 1] = obj;
}

void Main::checkCollides()
{
    int size = this->allGameObjects.size();
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (this->allGameObjects[i]->checkCollision(this->allGameObjects[j]))
            {
                this->allGameObjects[i]->informeCollide(true, this->allGameObjects[j]);
                this->allGameObjects[j]->informeCollide(true, this->allGameObjects[i]);
            }
        }
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            this->allGameObjects[i]->informeCollide(false, this->allGameObjects[j]);
            this->allGameObjects[j]->informeCollide(false, this->allGameObjects[i]);
        }
    }
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