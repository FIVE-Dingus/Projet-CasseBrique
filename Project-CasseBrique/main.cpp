#include <SFML/Graphics.hpp>
#include "main.h"
#include "gameObject.h"
using namespace sf;

int main()
{
    Main();

    return 0;
}

Main::Main()
{

    GameObject* gameObject = new GameObject(1, 2, 25, 5);
    gameObject->createCircle(300);

    
}