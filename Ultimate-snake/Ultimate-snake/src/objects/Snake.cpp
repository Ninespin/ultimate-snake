#include "Snake.h"

Snake::Snake() {
	bodypart* p1 = { new bodypart(1,1,&isdead) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,2,&isdead) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,3,&isdead) };
	addPart(p1);
	delete p1;

	p1 = { new bodypart(1,4,&isdead) };
	addPart(p1);
	delete p1;
	p1 = { new bodypart(1,5,&isdead) };
	addPart(p1);
	delete p1;

	dx = 1, dy = 0;
	queued_dx = dx;
	queued_dy = dy;

}
Snake::~Snake() {

}

void Snake::move() {
	if (!isdead) {
		dx = queued_dx;
		dy = queued_dy;
		for (std::vector<bodypart>::iterator i = parts.begin(); i != parts.end(); i++) {
			(*i).cycle();
			if (i == parts.begin()) {
				(*i).x += dx;
				(*i).y += dy;
			}
			else {
				(*i).x = (*(i - 1)).lastX;
				(*i).y = (*(i - 1)).lastY;
			}

		}
		checkIfDead();

	}
	
}

void Snake::checkIfDead() {
	//is out of the screen
	if ( parts.at(0).x >= NB_SQUARES_WIDTH || parts.at(0).x < 0 || parts.at(0).y >= NB_SQUARES_HEIGHT || parts.at(0).y < 0) {
		die();
		return;

	}else {
		for (std::vector<bodypart>::iterator i = parts.begin()+1; i != parts.end(); i++) {
			if ((*i) == parts.at(0)) {
				die();
				return;
			}

		}

	}

}

void Snake::die(){
	dx = dy = queued_dx = queued_dy = 0;
	isdead = true;
	/*for (std::vector<bodypart>::iterator i = parts.begin(); i != parts.end(); i++) {
		(*i).color.r = 255;
		(*i).color.g = 0;
		(*i).color.b = 255;

	}*/
}

void Snake::updateKeyboard(const Keyboard& key)
{
	if (key.isKeyJustPressed(GLFW_KEY_UP) && dy == 0)
	{
		queued_dy = 1;
		queued_dx = 0;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_DOWN) && dy == 0)
	{
		queued_dy = -1;
		queued_dx = 0;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_RIGHT) && dx == 0)
	{
		queued_dy = 0;
		queued_dx = 1;
	}
	else if (key.isKeyJustPressed(GLFW_KEY_LEFT) && dx == 0)
	{
		queued_dy = 0;
		queued_dx = -1;
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

bool Snake::isDead() {
	return isdead;
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






bodypart::bodypart(int x1, int y1,bool* b){
	x = x1;
	y = y1;
	parentIsDead = b;
}

void bodypart::draw() {
	glBegin(GL_TRIANGLE_FAN);

	if(*parentIsDead)
		glColor3f(0, 0, 0);
	else 
		glColor3f(color.r, color.g, color.b);

		glVertex2f(x+ width / 2, y+ height / 2);//center of the box
	glColor3f(color.r, color.g, color.b);
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glVertex2f(x, y);

	glEnd();
}

void bodypart::cycle() {
	if (lastX != x || lastY != y) {
		lastX = x;
		lastY = y;
	}
	
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
