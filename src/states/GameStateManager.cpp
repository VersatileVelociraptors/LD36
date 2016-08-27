#include "GameStateManager.h"

GameStateManager::GameStateManager(sf::RenderWindow *window){
	this->window = window;
}

GameStateManager::~GameStateManager(){
	delete currentState;
	delete musicManager;
}

void GameStateManager::render(){
	getCurrentState()->render();
}

void GameStateManager::update(float dt){
	getCurrentState()->update(dt);
}

void GameStateManager::set(StateEnumeration state){
	
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
