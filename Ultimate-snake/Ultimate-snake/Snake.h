#pragma once
#include <GLFW\glfw3.h>

struct bodypart {
	int x, y;
	bodypart * previousPart = 0, * nextPart = 0;

};

class Snake {
private:
	int dx, dy;
	bodypart * parts;

public:
	int getDx();
	int getDy();
	void setDx(int);
	void setDy(int);
	bodypart* getBodyparts();
	bodypart* getBodypartAt(int);
	void move();
	void draw();
};