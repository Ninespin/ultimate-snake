#pragma once
#include<ctime>

#include "..\misc\Color.h"


class Orb {
private:
	int x, y;
	Color color,fadeColor;
	std::clock_t lastTimeMarker, now;
	double deltaT,fadeLevel;

};