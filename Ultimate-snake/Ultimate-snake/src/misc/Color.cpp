#include "Color.h"
#include <iostream>


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

Color Color::fadeTo(Color originalColor, Color finalColor, double percent){
	if (percent < 0 || percent > 1) {
		std::cout << "\n[Error] : Color.fadeTo(Color,Color,double) : percent is not whithin [0,1] (given value:"<<percent<<")";
		std::cout << "\n\t-Aborting fade, the color given as first parameter will be returned to insure good function of the program.";
		return originalColor;
	}
	Color deviation = finalColor - originalColor;
	int nr = originalColor.r + deviation.r * percent;
	int ng = originalColor.g + deviation.g * percent;
	int nb = originalColor.b + deviation.b * percent;

	return Color(nr,ng,nb);
}