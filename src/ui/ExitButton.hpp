#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "Button.hpp"

class ExitButton : public Button
{
public:
	ExitButton(sf::RenderWindow *window);
	ExitButton(sf::RenderWindow *window, float x, float y);
	~ExitButton();
	
};

#endif //EXITBUTTON_HPP