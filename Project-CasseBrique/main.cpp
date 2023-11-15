#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "ball.h"
#include "rect.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{
    MyColor col1(0xff0000);
    MyColor col2(0x00ff00);
    MyColor col3(0x0000ff);
    MyColor col4(0xffffff);
    MyColor mix1;
    MyColor mix2;
    MyColor mix;
    for (int i = 0; i < 10; i++) {
        col1.mixin(col2, &mix1, i / 9.f);
        col3.mixin(col4, &mix2, i / 9.f);
        for (int j = 0; j < 10; j++)
        {
            mix1.mixin(mix2, &mix, j / 9.f);
            this->newGameObjects(new GameObject(Vect2(75 * i + 65, 30 * j + 100), Vect2(60, 20), mix));
        }
    }
    this->newGameObjects(new Ball(Vect2(400, 700), 10, MyColor(0xffffff)));
    this->newGameObjects(new MyRect(Vect2(400, 700), Vect2(60, 20), MyColor(0xff0ff0)));
    this->allGameObjects[101]->activeCollision();
    this->allGameObjects[101]->setSubdivisionOrigin({ 60, 2 });
    this->allGameObjects[101]->setOrigin({ 15, 1 });

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