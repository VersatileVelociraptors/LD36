#include "ExitButton.hpp"

ExitButton::ExitButton(sf::RenderWindow *window){
	this->window = window;

	if(!this->buttonTexture.loadFromFile("assets/images/exitbutton.png"))
		window->close();

	this->setTexture(buttonTexture);
	clicked = false;
}

ExitButton::ExitButton(sf::RenderWindow *window, float x, float y){

	if(!this->buttonTexture.loadFromFile("assets/images/exitbutton.png"))
		window->close();

	this->x = x;
	this->y = y;
	this->window = window;
	this->setTexture(buttonTexture);
	this->setPosition(x,y);
	clicked = false;
}

ExitButton::~ExitButton(){

}