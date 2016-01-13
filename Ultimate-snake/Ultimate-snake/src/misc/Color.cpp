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

const Color Color::fadeTo(Color originalColor, Color finalColor, float percent){

	if (percent < 0 || percent > 1.f) {
		std::cout << "\n[Error] : Color.fadeTo(Color,Color,double) : percent is not whithin [0,1] (given value:"<<percent<<")";
		std::cout << "\n\t-Aborting fade, the color given as first parameter will be returned to insure good function of the program.";
		return originalColor;
	}
	else {
		Color deviation = finalColor - originalColor;
		float nr = originalColor.r + deviation.r * percent;
		float ng = originalColor.g + deviation.g * percent;
		float nb = originalColor.b + deviation.b * percent;

		return Color(nr, ng, nb);
	}
	
}

Color::Color(){
	r = 0;
	g = 0;
	b = 0;
}