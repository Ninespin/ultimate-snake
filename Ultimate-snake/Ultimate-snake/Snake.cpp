#include "Snake.h"

Snake::Snake() {
	bodypart* p1 = { new bodypart(1,1) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,2) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,3) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,4) };
	addPart(p1);
	delete p1;

	dx = 1, dy = 0;
	

}
Snake::~Snake() {

}

void Snake::move() {
	for (std::vector<bodypart>::iterator i = parts.begin(); i != parts.end(); i++) {
		(*i).cycle();
		if (i == parts.begin()) {
			(*i).x += dx;
			(*i).y += dy;
#if 0
			//base AI (aka remove when keyboard input is processed)
			if ((*i).x >= 9 || (*i).x <= 0) {
				dx = -dx;
				dy = -dy;
			}
#endif			
		}else{
			(*i).x = (*(i - 1)).lastX;
			(*i).y = (*(i - 1)).lastY;
		}
	}

}

void Snake::updateKeyboard(const Keyboard& key)
{
	if (key.isKeyJustPressed(GLFW_KEY_UP) && dy == 0)
	{
		dy = 1;
		dx = 0;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_DOWN) && dy == 0)
	{
		dy = -1;
		dx = 0;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_RIGHT) && dx == 0)
	{
		dy = 0;
		dx = 1;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_LEFT) && dx == 0)
	{
		dy = 0;
		dx = -1;
	}
}
	
void Snake::draw() {
	
	for (std::vector<bodypart>::reverse_iterator i = parts.rbegin(); i != parts.rend(); i++) {
		
		if (i+1 == parts.rend()) {//head
			(*i).color.changeColor(1.f,0.f,0.f);
		}
		if (i == parts.rbegin()) {//tail
			(*i).color.changeColor(1.f, 1.f, 0.f);
		}
		
		(*i).draw();

	}

}

void Snake::refreshBodyparts() {
	
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
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(color.r, color.g, color.b);
		glVertex2f(x+ width / 2, y+ height / 2);//center of the box

		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glVertex2f(x, y);

	glEnd();
}

void bodypart::cycle() {
	lastX = x;
	lastY = y;
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
