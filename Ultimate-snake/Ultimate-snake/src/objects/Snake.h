#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>
#include "..\input\Keyboard.h"
#include "..\constants\windowConstants.h"
#include "..\misc\Color.h"
#include "Orb.h"
#include "Wall.h"



struct bodypart {
	int x, y,lastX,lastY;
	Color color = Color(1.f,1.f,1.f);
	const float width = 1, height = 1;
	bool* parentIsDead;

	void draw();
	void cycle();
	bodypart(int,int,bool*);


	inline bool operator==(const bodypart& p1){
		if (p1.x == this->x && p1.y == this->y)return true;
		return false;
	}
};

class Snake {
private:
	bool isdead = false;
	int dx, dy,queued_dx,queued_dy;
	std::vector<bodypart> parts;
	double moveDelayMS;

public:
	static const double minimalMoveDelayMS;
	static const double moveDelayStepMS;
	double getMoveDelayMS();
	int getDx();
	int getDy();
	bool isDead();
	void setMoveDelayMS(double);
	void setDx(int);
	void setDy(int);
	std::vector<bodypart> getBodyparts();
	bodypart* getBodypartAt(int);
	void move();
	void draw();
	void updateKeyboard(const Keyboard& key);
	void refreshBodyparts();
	void addPart(bodypart*);
	void addPart();
	void checkIfDead();
	void die();
	bool isOverOrb(Orb*);
	bool isOverWall(Wall*);
	Snake();
	~Snake();
};