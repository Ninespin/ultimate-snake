#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>
#include "src\input\Keyboard.h"

struct Color {
	float r, g, b;
	Color(float,float,float);
	void changeColor(float, float, float);

};

struct bodypart {
	int x, y,lastX,lastY;
	Color color = Color(1.f,1.f,1.f);
	const float width = 1, height = 1;

	void draw();
	void cycle();
	bodypart(int,int);


	inline bool operator==(const bodypart& p1){
		if (p1.x == this->x && p1.y == this->y)return true;
		return false;
	}
};

class Snake {
private:
	int dx, dy;
	std::vector<bodypart> parts;


public:
	int getDx();
	int getDy();
	void setDx(int);
	void setDy(int);
	std::vector<bodypart> getBodyparts();
	bodypart* getBodypartAt(int);
	void move();
	void draw();
	void updateKeyboard(const Keyboard& key);
	void refreshBodyparts();
	void addPart(bodypart*);
	void checkIfDead();
	void die();
	Snake();
	~Snake();
};