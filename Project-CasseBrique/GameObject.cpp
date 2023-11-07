#include "GameObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameObject::GameObject(int x, int y, int w, int h) {

}

void GameObject::createRect(int w, int h) {

}

void GameObject::createCircle(float d) {
	CircleShape shape(d);
	shape.setFillColor(Color::Green);
}