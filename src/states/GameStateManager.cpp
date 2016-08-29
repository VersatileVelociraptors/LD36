#include "GameStateManager.hpp"
#include <iostream>

GameStateManager::GameStateManager(sf::RenderWindow *window){
	this->window = window;

	playState = new PlayState(window);
	menuState = new MenuState(this);
	musicManager = new MusicManager(window);
	musicManager->addAllMusicInAssets();

}

GameStateManager::~GameStateManager(){
	delete menuState;
	delete playState;
	delete musicManager;
}

void GameStateManager::render(){
	getCurrentState()->render();
}

void GameStateManager::update(float dt){
	getCurrentState()->update(dt);
}

void GameStateManager::set(StateEnumeration state){
	if(state == MENU)
		currentState = menuState;
	else if(state == PLAY)
		currentState = playState;
	else if(state == END)
		std::cout << "Placeholder" << std::endl;
}

sf::RenderWindow* GameStateManager::getWindow(){
	return window;
}

MusicManager* GameStateManager::getMusicManager(){
	return this->musicManager;
}

State* GameStateManager::getCurrentState(){
	return currentState;
}

void GameStateManager::setCurrentState(State* state){
	currentState = state;
}
