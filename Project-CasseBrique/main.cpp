#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

Main::Main()
{
    this->start();
}

void Main::start()
{
    GameObject gameObject(Vect2(0, 0), 100);

    gameObject.createCircle();
    GameObject gameObject2(Vect2(100, 100), 100, MyColor(0xffffff));
    gameObject2.createCircle();

    while (this->window.isOpen())
    {
        this->window.drawGameObject(gameObject);
        this->window.drawGameObject(gameObject2);
        this->window.draw();
    }
}

int main()
{
    cout << "starting..";
    Main myMain;
    cout << "closing..";

    return 0;
}