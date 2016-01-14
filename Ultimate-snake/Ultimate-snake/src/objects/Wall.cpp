#include "Wall.h"
#include "..\misc\Color.h"
#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef TIME_H
#include <time.h>
#endif
#ifndef WINDOWCONSTANTS_H
#include "..\constants\windowConstants.h"
#endif

Wall::Wall(int x1, int y1) {
	x = x1, y = y1;
	lastTimeMarker = lastMoveTimeMarker = std::clock();
	fadeSpeedMS = 50;
	moveSpeedMS = 10000;
	fadeLevel = 0.f;
	deltaT = 0.f;
	fadeStep = 0.01;
}

void Wall::makeDeltaT() {
	deltaT = (now - lastTimeMarker) / (double)(CLOCKS_PER_SEC / 1000);
}
void Wall::makeDeltaTNow() {
	now = std::clock();
	makeDeltaT();
}
void Wall::makeDeltaT(std::clock_t * t, double* delta) {
	*delta = (now - (*t ) ) / (double)(CLOCKS_PER_SEC / 1000);
}
void Wall::makeDeltaTNow(std::clock_t * t, double* delta) {
	now = std::clock();
	makeDeltaT(t,delta);
}



void Wall::update() {
	makeDeltaTNow(&lastTimeMarker, &deltaT);//deltaT for fade
	makeDeltaTNow(&lastMoveTimeMarker, &moveDeltaT);//deltaT for move
	if (deltaT >= fadeSpeedMS || fadingout) {
		if (fadeLevel + fadeStep <= 1 && fadeLevel + fadeStep >= 0) {
			fadeLevel += fadeStep;
			currentColor = originalColor.fadeTo(originalColor, fadeColor, fadeLevel);
		}

		lastTimeMarker = now;
	}
	if (moveDeltaT >= moveSpeedMS-1500 && !fadingout) {//here 1500ms is about enough time for it to fadeout before moving
		fadingout = true;
		fadeStep = -fadeStep;
	}

	if (moveDeltaT >= moveSpeedMS) {
		move();
		fadingout = false;
		fadeStep = -fadeStep;
		lastMoveTimeMarker = now;
	}

	draw();
}

void Wall::draw() {
	glBegin(GL_LINE_LOOP);
	glColor3f(currentColor.r, currentColor.g, currentColor.b);
		glVertex2f(x, y);
		glVertex2f(x+width, y);
		glVertex2f(x+width, y+height);
		glVertex2f(x, y+height);
	glEnd();

}

void Wall::move() {
	resetFade();
	srand(time(NULL));
	x = rand() % NB_SQUARES_WIDTH;
	y = rand() % NB_SQUARES_HEIGHT;

}

void Wall::resetFade() {
	fadeLevel = 0;
	currentColor = originalColor;
	lastTimeMarker = std::clock();
}

//get
int Wall::getX() {
	return x;
}
int Wall::getY() {
	return y;
}
double Wall::getDeltaT() {
	return deltaT;
}
