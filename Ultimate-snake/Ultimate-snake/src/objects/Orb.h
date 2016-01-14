#pragma once
#include<ctime>
#include <GLFW\glfw3.h>

#include "..\misc\Color.h"


class Orb {
private:
	int x, y;
	Color originalColor = Color(0,0,0),fadeColor = Color(1.f, 0.f, 0.5f),currentColor;
	std::clock_t lastTimeMarker, now;
	double deltaT;
	float fadeLevel,fadeStep, fadeSpeedMS,width = 1, height = 1;
	bool lockdraw = false;

public:
	Orb(int,int);
	int getX();
	int getY();
	double getDeltaT();
	void makeDeltaT();
	void makeDeltaTNow();
	void update();
	void draw();
	void move();
	void resetFade();
};