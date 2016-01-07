#include "Snake.h"

Snake::Snake() {
	parts = new bodypart[2];
	
	(*parts).nextPart = (parts + 1);
	(*(parts + 1)).previousPart = parts;

}
Snake::~Snake() {
	delete parts;
}

void Snake::move() {
	int i = 0;
	/*while ( (*(parts+i)).nextPart != 0 ) {

		if ((*(parts + i)).previousPart == 0) {
			(*(parts + i)).x += dx;
			(*(parts + i)).y += dy;
		}
		else {
			(*(parts + i)).x += (*((*(parts + i)).previousPart)).x;
			(*(parts + i)).y += (*((*(parts + i)).previousPart)).y;
		}

		i++;
	}*/
	

}

void Snake::draw() {
	

	int i = -1;
	do{
		i++;
		
		(*(parts+i)).draw(i);

		
	} while ((*(parts + i)).nextPart != 0);

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






void bodypart::draw(int i) {
	glBegin(GL_TRIANGLES);

	glColor3f(1.f, 1.f, 1.f);

	glVertex2f(0.5f-width*i, 0.5f);
	glVertex2f(0.75f- width*i, 0.5f);
	glVertex2f(0.5f- width*i, 0.75f);

	glEnd();
}