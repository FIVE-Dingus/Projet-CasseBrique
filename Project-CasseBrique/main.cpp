#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
using namespace sf;

Main::Main()
{
    this->start();
}

void Main::start()
{
    this->window.setParams(500, 500);

    GameObject gameObject(1, 2, 300);
    gameObject.createCircle();

    while (this->window.isOpen())
    {
        this->window.drawGameObject(gameObject);
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