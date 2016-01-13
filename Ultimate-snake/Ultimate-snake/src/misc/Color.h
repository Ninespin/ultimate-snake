#pragma once


struct Color {
	float r, g, b;
	Color(float, float, float);
	Color();
	void changeColor(float, float, float);
	const static Color fadeTo(Color original, Color Final, float percent);

	inline Color operator-(const Color& c1) {
		return Color(this->r - c1.r, this->g - c1.g, this->b - c1.b);
	}
};