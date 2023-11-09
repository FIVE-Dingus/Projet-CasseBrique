#pragma once
#include "window.h"
#include <iostream>
using namespace std;

class Main
{
private:
	MyWindow window;
	vector<GameObject> allGameObjects;

public:
	Main();

private:
	void initGameObjects();
	void start();
};