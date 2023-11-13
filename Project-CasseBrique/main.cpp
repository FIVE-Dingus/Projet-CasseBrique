#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "ball.h"
#include "rect.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    for (int i = 65; i < 750; i += 75) {

        this->newGameObjects(new MyRect(Vect2(i, 100), Vect2(60, 20), MyColor(0xfff000)));
        this->newGameObjects(new MyRect(Vect2(i, 130), Vect2(60, 20), MyColor(0xff0000)));
        this->newGameObjects(new MyRect(Vect2(i, 160), Vect2(60, 20), MyColor(0x00ff00)));
        this->newGameObjects(new MyRect(Vect2(i, 190), Vect2(60, 20), MyColor(0xfff0ff)));
        this->newGameObjects(new MyRect(Vect2(i, 220), Vect2(60, 20), MyColor(0xff0ff0)));
    }
    this->newGameObjects(new Ball(Vect2(400, 700), 50, MyColor(0xffffff))); 
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
        this->allGameObjects[i]->update(deltaTime * this->worldSpeed, deltaTime);
    }
}

void Main::newGameObjects(GameObject* obj)
{
    this->allGameObjects.resize(this->allGameObjects.size() + 1);
    obj->setWindow(this->window.getSfWindow());
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