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
    GameObject gameObject(Vect2(0, 0), 500);
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