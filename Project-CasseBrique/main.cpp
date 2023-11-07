#include <SFML/Graphics.hpp>
#include "main.h"
using namespace sf;

int main()
{
    Main();

    return 0;
}

Main::Main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.setSize(Vector2u(200, 200));
        window.clear();
        window.draw(shape);
        window.display();
    }
}