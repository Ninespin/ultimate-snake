#include "Keyboard.h"
#include "../graphics/Window.h"

Keyboard::Keyboard(graphics::Window& win)
{
	win.setKeyboard(this);

	for (unsigned i = 0; i < KEYBOARD_MAX_KEY_NUM; i++)
	{
		keyPressedAbsolute[i] = false;
		keyJustPressed[i] = false;
	}
}

Keyboard::~Keyboard() 
{

}

void Keyboard::pressKey(int index, int action)
{
	if (index < KEYBOARD_MAX_KEY_NUM && index >= 0)
	{
		keyPressedAbsolute[index] = (action != GLFW_RELEASE);
		keyJustPressed[index] = (action == GLFW_PRESS);
	}
}

bool Keyboard::isKeyPressed(unsigned int index) const
{
	if(index < KEYBOARD_MAX_KEY_NUM && index >= 0)
	{
		return keyPressedAbsolute[index];
	}
	else
	{
		return false;
	}
}

bool Keyboard::isKeyJustPressed(unsigned int index) const
{
	if (index < KEYBOARD_MAX_KEY_NUM && index >= 0)
	{
		return keyJustPressed[index];
	}
	else
	{
		return false;
	}
}

void Keyboard::reset()
{
	for (unsigned i = 0; i < KEYBOARD_MAX_KEY_NUM; i++)
	{
		keyJustPressed[i] = false;
	}
}