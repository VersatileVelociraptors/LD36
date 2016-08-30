#include "MenuState.hpp"
MenuState::MenuState(GameStateManager* manager){
	this->manager = manager;
	this->window = manager->getWindow();
	this->startButton = new StartButton(window, window->getSize().x/2-110, window->getSize().y/2-100);
	this->exitButton = new ExitButton(window, startButton->getPosition().x + 20, startButton->getPosition().y+startButton->getLocalBounds().height+10);

	if (!font.loadFromFile("assets/fonts/arial.ttf"))
		window->close();
	
	line1.setFont(font);
	line1.setCharacterSize(25);
	line1.setColor(sf::Color::Black);
	line1.setString("Long ago, to escape mass extinction, the velociraptors built a machine capable of inter-dimensional travel.");
	line1.setPosition(30,500);
	
	line2.setFont(font);
	line2.setCharacterSize(25);
	line2.setColor(sf::Color::Black);
	line2.setString("Millions of years later, that machine has come to life. Welcome to Raptroid Prime.");
	line2.setPosition(150,550);
}

MenuState::~MenuState(){
	delete startButton;
	delete exitButton;
}

void MenuState::update(float dt){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		float posx = sf::Mouse::getPosition(*window).x;
		float posy = sf::Mouse::getPosition(*window).y;
		startButton->update(posx, posy);
		exitButton->update(posx, posy);
	}

	if(startButton->isClicked()){
		manager->set(PLAY);
		return;
	}

	if(exitButton->isClicked()){
		window->close();
	}
}

void MenuState::render(){
	window->clear(sf::Color::White);
	window->draw(*startButton);
	window->draw(*exitButton);
	window->draw(line1);
	window->draw(line2);
}
