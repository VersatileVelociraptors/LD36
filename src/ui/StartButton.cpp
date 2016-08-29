#include "StartButton.hpp"

StartButton::StartButton(sf::RenderWindow *window, float x, float y){

	if(!this->buttonTexture.loadFromFile("assets/images/playbutton.png"))
		window->close();

	this->x = x;
	this->y = y;
	this->window = window;
	this->setTexture(buttonTexture);
	this->setPosition(x,y);
	clicked = false;

}

StartButton::~StartButton(){

}