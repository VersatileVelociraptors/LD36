#include "PlayState.hpp"


PlayState::PlayState(sf::RenderWindow* window, GameStateManager* manager){
	this->window = window;

	this->player = new Player(new Level(window));
	
	this->manager = manager;
}

PlayState::~PlayState(){
	delete player;
}

void PlayState::start(){
	player->get_level()->changeMessage(MESSAGE_1);
}

void PlayState::update(float dt){
	player->get_level()->update(dt);
	player->update(dt);
	if (player->get_level()->getCurrentLevel() >= LEVEL_COUNT) {
		manager->set(END);
	}
}

void PlayState::render(){
	player->get_level()->render();
	window->draw(*player);// draw player texture
}
