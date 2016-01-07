#include "Snake.h"



void Snake::move() {
	int i = 0;
	while ( (*(parts+i)).nextPart != 0 ) {

		if ((*(parts + i)).previousPart == 0) {
			(*(parts + i)).x += dx;
			(*(parts + i)).y += dy;
		}
		else {
			(*(parts + i)).x += (*((*(parts + i)).previousPart)).x;
			(*(parts + i)).y += (*((*(parts + i)).previousPart)).y;
		}

		i++;
	}

}







//gets
int Snake::getDx() {
	return dx;
}

int Snake::getDy() {
	return dy;
}

bodypart* Snake::getBodyparts() {
	return parts;
}

bodypart* Snake::getBodypartAt(int i) {
	return (parts + i);
}


//sets
void Snake::setDx(int x){
	dx = x;
}

void Snake::setDy(int y) {
	dy = y;
}

