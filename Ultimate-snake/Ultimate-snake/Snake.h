#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>


struct Color {
	float r, g, b;
	Color(float,float,float);
	void changeColor(float, float, float);

};

struct bodypart {
	int x, y,lastX,lastY;
	Color color = Color(1.f,1.f,1.f);
	const float width = 1, height = 1;
	//bodypart * previousPart = 0, * nextPart = 0;

	void draw();
	void cycle();
	bodypart(int,int);

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
	void refreshBodyparts();
	void addPart(bodypart*);
	Snake();
	~Snake();
};