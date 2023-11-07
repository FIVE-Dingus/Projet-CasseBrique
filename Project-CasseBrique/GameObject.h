#pragma once


class GameObject {
private:
	int x;
	int y;
	int h;
	int w;
	float d;
	bool shape;

public:
	GameObject(int x, int y, int w, int h);

	void createRect(int w, int h);
	void createCircle(float d);

};