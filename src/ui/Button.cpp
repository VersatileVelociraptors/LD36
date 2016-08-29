#include "Button.hpp"

Button::Button(){

}

Button::Button(sf::RenderWindow *window, sf::Texture texture, float x, float y){
	this->x = x;
	this->y = y;
	this->window = window;
	this->buttonTexture = texture;
	this->setTexture(buttonTexture);
	this->setPosition(x,y);
	clicked = false;
}

Button::~Button(){

}

void Button::update(float x, float y){
	this->x = getPosition().x;
	this->y = getPosition().y;
	if(x > this->x && x < this->x + this->getTextureRect().width
	 && y > this->y && y < this->y + this->getTextureRect().height){
			clicked = true;
		}
}

bool Button::isClicked(){
	return clicked;
}