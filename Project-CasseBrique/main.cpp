#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    this->newGameObjects(GameObject(Vect2(100, 100), 100, MyColor(0x00ff00)));
    this->newGameObjects(GameObject(Vect2(50, 50), Vect2(100, 100), MyColor(0x000000)));
    this->newGameObjects(GameObject(Vect2(150, 150), Vect2(100, 100), MyColor(0x000000)));
}

void Main::start()
{
    while (this->window.isOpen())
    {
        this->window.drawGameObjects(this->allGameObjects);
        this->window.draw();
    }
}

void Main::newGameObjects(GameObject obj)
{
    this->allGameObjects.resize(this->allGameObjects.size() + 1);
    this->allGameObjects[this->allGameObjects.size() -1] = obj;
}

Main::Main()
{
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