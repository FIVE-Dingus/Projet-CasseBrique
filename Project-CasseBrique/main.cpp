#include <SFML/Graphics.hpp>
#include "main.h"
#include "gameObject.h"
#include "window.h"
using namespace sf;

int main()
{
    Main();

    return 0;
}

Main::Main()
{
    this->window.setParams(500, 500);

    GameObject gameObject(1, 2, 25, 5);
    gameObject.createCircle(300);

    while (this->window.isOpen())
    {
        this->window.drawGameObject(gameObject);
    }
}