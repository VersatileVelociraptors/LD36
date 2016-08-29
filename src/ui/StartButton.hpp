#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "Button.hpp"

class StartButton : public Button
{
public:
	StartButton(sf::RenderWindow *window, float x, float y);
	~StartButton();
	
};

#endif //STARTBUTTON_HPP