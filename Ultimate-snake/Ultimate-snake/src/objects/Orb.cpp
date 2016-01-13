#include "Orb.h"
#include "..\misc\Color.h"

Orb::Orb(int x1, int y1) {
	x = x1, y = y1;
	lastTimeMarker = std::clock();
	fadeSpeedMS = 50;
	fadeLevel = 0.f;
	deltaT = 0.f;
	fadeStep = 0.01;
}

void Orb::makeDeltaT() {
	deltaT = (now - lastTimeMarker) / (double)(CLOCKS_PER_SEC / 1000);
}
void Orb::makeDeltaTNow() {
	now = std::clock();
	makeDeltaT();
}



void Orb::update() {
	makeDeltaTNow();
	if(deltaT >= fadeSpeedMS){
		if (fadeLevel + fadeStep <= 1 && fadeLevel + fadeStep >= 0) {
			fadeLevel += fadeStep;
			currentColor = originalColor.fadeTo(originalColor, fadeColor, fadeLevel);
		}
		
		lastTimeMarker = now;
	}

	draw();
}

void Orb::draw() {
	glBegin(GL_TRIANGLE_FAN);

	
	glColor3f(0, 0, 0);
		glVertex2f(x + width / 2, y + height / 2);//center of the box
	glColor3f(currentColor.r, currentColor.g, currentColor.b);
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glVertex2f(x, y);

	glEnd();
}

//get
int Orb::getX() {
	return x;
}
int Orb::getY() {
	return y;
}
double Orb::getDeltaT() {
	return deltaT;
}
