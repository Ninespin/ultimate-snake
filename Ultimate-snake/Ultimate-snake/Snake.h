#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

struct bodypart {
	int x, y;
	const float width = 0.1, height = 0.1;
	bodypart * previousPart = 0, * nextPart = 0;

	void draw(int);

};

class Snake {
private:
	int dx, dy;
	bodypart*parts;


public:
	int getDx();
	int getDy();
	void setDx(int);
	void setDy(int);
	bodypart* getBodyparts();
	bodypart* getBodypartAt(int);
	void move();
	void draw();
	Snake();
	~Snake();
};