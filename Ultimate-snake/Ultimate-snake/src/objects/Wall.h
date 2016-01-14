#pragma once
#include "..\misc\Color.h"
#include<ctime>
#include <GLFW\glfw3.h>

class Wall {
private:
	int x, y;
	Color originalColor = Color(0, 0, 0), fadeColor = Color(0.5f, 0.5f, 0.5f), currentColor;
	std::clock_t lastTimeMarker, lastMoveTimeMarker, now;
	double deltaT, moveDeltaT;
	float fadeLevel, fadeStep, fadeSpeedMS, moveSpeedMS, width = 1, height = 1;
	bool lockdraw = false, fadingout = false;

public:
	Wall(int, int);
	int getX();
	int getY();
	double getDeltaT();
	void makeDeltaT();
	void makeDeltaTNow();
	void makeDeltaT(std::clock_t*, double*);
	void makeDeltaTNow(std::clock_t*, double*);
	void update();
	void draw();
	void move();
	void resetFade();
};