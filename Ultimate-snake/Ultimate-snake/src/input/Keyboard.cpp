#include "Keyboard.h"
#include "../graphics/Window.h"

Keyboard::Keyboard(graphics::Window& win)
{
	win.setKeyboard(this);

	for (unsigned i = 0; i < KEYBOARD_MAX_KEY_NUM; i++)
	{
		b[i] = false;
	}
}

Keyboard::~Keyboard() 
{

}

void Keyboard::pressKey(int index, int action)
{
	if (index < KEYBOARD_MAX_KEY_NUM && index >= 0)
	{
		b[index] = (action != GLFW_RELEASE);
	}
}

bool Keyboard::isKeyPressed(unsigned int index) const
{
	if(index < KEYBOARD_MAX_KEY_NUM && index >= 0)
	{
		return b[index];
	}
	else
	{
		return false;
	}
}