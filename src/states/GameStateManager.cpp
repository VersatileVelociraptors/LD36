#include "GameStateManager.hpp"

GameStateManager::GameStateManager(sf::RenderWindow *window){
	this->window = window;

	playState = new PlayState(window, this);
	menuState = new MenuState(this);
	endState = new EndState(this);
	musicManager = new MusicManager(window);
	musicManager->addAllMusicInAssets();
	musicManager->loop("music");
	musicManager->play("music");
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
	
	// bye bye 16 year old skrillex
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && !muteHeld){
		if (!muted) {
			musicManager->stop();
		} else {
			musicManager->loop("music");
			musicManager->play("music");
		}
		muted = !muted;
	}
	muteHeld = sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
}

void GameStateManager::set(StateEnumeration state){
	if(state == MENU){
		currentState = menuState;
	}else if(state == PLAY){
		currentState = playState;
		playState->start();
	}else if(state == END){
		currentState = endState;
	}
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
