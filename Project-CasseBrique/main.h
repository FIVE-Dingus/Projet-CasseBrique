#pragma once
#include "window.h"
#include <iostream>
using namespace std;

class Main
{
private:
	MyWindow window;
	vector<GameObject> allGameObjects;
	float worldSpeed;
	Clock clock;

public:
	Main();

private:
	void initGameObjects();
	void newGameObjects(GameObject obj);
	void updateGameObject();
	void start();
};