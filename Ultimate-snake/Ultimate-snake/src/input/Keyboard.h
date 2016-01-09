#pragma once

#include <GLFW\glfw3.h>

namespace graphics {
	class Window;
}

#define KEYBOARD_MAX_KEY_NUM GLFW_KEY_LAST


class Keyboard
{
private:
	bool b[KEYBOARD_MAX_KEY_NUM];

public:
	Keyboard(graphics::Window& masterWindow);
	~Keyboard();

	bool isKeyPressed(unsigned int index) const;
	void pressKey(int index, int action);
};