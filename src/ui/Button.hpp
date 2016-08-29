#ifndef BUTTON_HPP
#define BUTTON_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
public:
	Button();
	Button(sf::RenderWindow *window);
	Button(sf::RenderWindow *window, sf::Texture texture, float x, float y);
	~Button();
	void update(float x, float y);
	bool isClicked();

protected:
	sf::Texture buttonTexture;
	float x, y;
	bool clicked;
	sf::RenderWindow *window;
	
};

#endif //BUTTON_HPP