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
    GameObject gameObject(Vect2(0, 0), 200);
    gameObject.setColor(MyColor(0x0000ff));
    gameObject.createRect();
    GameObject gameObject2(Vect2(100, 100), 200, MyColor(0xff0000));
    gameObject2.createRect();

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