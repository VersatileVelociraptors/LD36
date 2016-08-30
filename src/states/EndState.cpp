#include "EndState.hpp"

EndState::EndState(GameStateManager* manager){
	this->manager = manager;
	this->window = manager->getWindow();
	this->exitButton = new ExitButton(window, 550, 300);
}

EndState::~EndState(){
	delete exitButton;
}

void EndState::update(float dt){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		float posx = sf::Mouse::getPosition(*window).x;
		float posy = sf::Mouse::getPosition(*window).y;
		exitButton->update(posx, posy);
		if(exitButton->isClicked()){
			window->close();
		}
	}
}

void EndState::render(){
	window->clear(sf::Color::White);
	window->draw(*exitButton);
}
