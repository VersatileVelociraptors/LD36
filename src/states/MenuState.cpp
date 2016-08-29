#include "MenuState.hpp"

MenuState::MenuState(GameStateManager* manager){
	this->manager = manager;
	this->window = manager->getWindow();
	this->startButton = new StartButton(window, window->getSize().x/2-110, window->getSize().y/2-100);
	this->exitButton = new ExitButton(window, startButton->getPosition().x, startButton->getPosition().y+startButton->getLocalBounds().height+10);
	if(!this->menuGraphicTexture.loadFromFile("assets/images/Graphic.png"))
		window->close();
	menuGraphicSprite = new sf::Sprite(menuGraphicTexture);
	menuGraphicSprite->setOrigin(menuGraphicSprite->getLocalBounds().width/2, menuGraphicSprite->getLocalBounds().height/2);
	menuGraphicSprite->setPosition(startButton->getPosition().x + startButton->getLocalBounds().width/2, startButton->getPosition().y-menuGraphicSprite->getLocalBounds().height/2 - 10);
}

MenuState::~MenuState(){
	delete menuGraphicSprite;
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
	window->draw(*menuGraphicSprite);
	window->draw(*startButton);
	window->draw(*exitButton);
}
