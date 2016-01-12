#pragma once


struct Color {
	float r, g, b;
	Color(float, float, float);
	void changeColor(float, float, float);
	Color fadeTo(Color original, Color Final, double percent);

	inline Color operator-(const Color& c1) {
		return Color(this->r - c1.r, this->g - c1.g, this->b - c1.b);
	}
};