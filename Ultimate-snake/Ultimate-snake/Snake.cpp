#include "Snake.h"

Snake::Snake() {
	bodypart* p1 = { new bodypart(1,1) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(5,5) };
	addPart(p1);
	delete p1;
	
	

}
Snake::~Snake() {

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
	
	for (std::vector<bodypart>::iterator i = parts.begin(); i != parts.end(); i++) {
		if (i == parts.begin()) {
			(*i).color.changeColor(1.f,0.f,0.f);
		}
		if (&i == &(parts.end()-1)) {
			(*i).color.changeColor(1.f, 0.f, 0.f);
			//(*i).nextPart = &(*(i + 1));
		}
		
		(*i).draw();

	}

}

void Snake::refreshBodyparts() {
	for (std::vector<bodypart>::iterator i = parts.begin(); i != parts.end(); i++) {
		if (i != parts.begin()) {
			//(*i).previousPart = &(*(i - 1));
		}
		if (i < parts.end()) {
			//(*i).nextPart = &(*(i + 1));
		}
	}
}

void Snake::addPart(bodypart* p) {
	parts.push_back(*p);
	refreshBodyparts();


}




//gets
int Snake::getDx() {
	return dx;
}

int Snake::getDy() {
	return dy;
}

std::vector<bodypart> Snake::getBodyparts() {
	return parts;
}

bodypart* Snake::getBodypartAt(int i) {
	return &(parts.at(i));
}


//sets
void Snake::setDx(int x){
	dx = x;
}

void Snake::setDy(int y) {
	dy = y;
}






bodypart::bodypart(int x1, int y1){
	x = x1;
	y = y1;
}

void bodypart::draw() {
	glBegin(GL_TRIANGLES);

	glColor3f(color.r, color.g, color.b);

	glVertex2f(x, y);
	glVertex2f(x+width, y);
	glVertex2f(x, y+height);

	glEnd();
}





Color::Color(float r1, float g1, float b1) {
	r = r1;
	g = g1;
	b = b1;
}

void Color::changeColor(float r1, float g1, float b1) {
	r = r1;
	g = g1;
	b = b1;
}
