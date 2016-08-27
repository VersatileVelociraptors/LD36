#include "PlayState.hpp"

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	this->level = new Level("assets/levels/level02.txt", window);
	
	Player* player = new Player(level);
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	level->setPlayer(player);
}

PlayState::~PlayState(){
	delete level;
}

void PlayState::update(float dt){
	level->update(dt);
}

void PlayState::render(){
	level->render();
	window->draw(*level->getPlayer());
}
