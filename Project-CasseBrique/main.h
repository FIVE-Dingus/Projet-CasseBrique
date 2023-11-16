#pragma once
#include "window.h"
#include <iostream>
using namespace std;

class Main
{
private:
	MyWindow window;
	vector<GameObject*> allGameObjects;
	float worldSpeed;
	Clock clock;

public:
	Main();
	void newGameObjects(GameObject* obj);

private:
	void initGameObjects();
	void updateGameObject();
	void start();
	void checkCollides();
};