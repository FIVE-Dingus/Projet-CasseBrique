#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
#include "vect.h"
using namespace sf;

void Main::initGameObjects()
{

}

void Main::start()
{
    GameObject gameObject(Vect2(50, 50), Vect2(100, 100));
    gameObject.setColor(MyColor(0x0000ff));

    GameObject gameObject2(Vect2(150, 150), Vect2(100, 100), MyColor(0xff0000));
    
    GameObject gameObject3(Vect2(150, 150), 100, MyColor(0x00ff00));

    while (this->window.isOpen())
    {
        this->window.drawGameObject(gameObject);
        this->window.drawGameObject(gameObject2);
        this->window.drawGameObject(gameObject3);
        this->window.draw();
    }
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