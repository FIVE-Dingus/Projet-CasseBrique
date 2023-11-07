#include <SFML/Graphics.hpp>
#include "main.h"
#include "GameObject.h"
using namespace sf;

int main()
{
    Main();

    return 0;
}

Main::Main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
    GameObject* gameObject = new GameObject(1, 2, 25, 5);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.setSize(Vector2u(500, 500));
        window.clear();
        window.draw(shape);
        window.display();
    }
}