#include "PlayState.hpp"


#include <string>//for testing

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	this->level = new Level("assets/levels/level02.txt", window);
	
	Player* player = new Player(level);
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	player->set_true((int) window->getSize().x/2,(int) window->getSize().y/2);
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

	//for testing
	std::string coordinate_string="";
	

	//coordinate_string+=std::to_string(level->getPlayer()->get_true().x)+", "+std::to_string(level->getPlayer()->get_true().y);


	coordinate_string+=std::to_string(level->getPlayer()->get_grid().x)+", "+std::to_string(level->getPlayer()->get_grid().y);
	sf::Text coordinates;
	coordinates.setFont(level->font);
	coordinates.setCharacterSize(12);
	coordinates.setPosition(level->getPlayer()->getPosition().x, level->getPlayer()->getPosition().y);
	coordinates.setString(coordinate_string);
	coordinates.setColor(sf::Color::White);
	window->draw(coordinates);
}
