#include "GameStateManager.h"
#include <iostream>

GameStateManager::GameStateManager(sf::RenderWindow *window){
	this->window = window;
}

GameStateManager::~GameStateManager(){
	delete peek();
	delete musicManager;
}

void GameStateManager::set(int state){
	push(state);
}

void GameStateManager::push(int state){}

void GameStateManager::pop(){
	states.pop();
}

State* GameStateManager::peek(){
	return states.top();
}

void GameStateManager::render(){
	peek()->render();
}

void GameStateManager::update(float dt){
	peek()->update(dt);
}

sf::RenderWindow* GameStateManager::getWindow(){
	return window;
}

MusicManager* GameStateManager::getMusicManager(){
	return this->musicManager;
}
