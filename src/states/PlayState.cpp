#include "PlayState.hpp"

#include <cstring>
#include <string>//for testing

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	
	std::string str = "assets/levels/level02.txt";
	char cstr[str.length() - 1];
	std::strcpy(cstr, str.c_str());
	this->level = new Level(cstr, window);
	
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
	window->draw(*level->getPlayer());// draw player texture

	//for testing
	std::string coordinate_string="";
	

	//coordinate_string+=std::to_string(level->getPlayer()->get_true().x)+", "+std::to_string(level->getPlayer()->get_true().y);


	coordinate_string+=std::to_string(level->getPlayer()->get_grid().x)+", "+std::to_string(level->getPlayer()->get_grid().y);
	sf::Text coordinates;
	coordinates.setFont(level->getFont());
	coordinates.setCharacterSize(12);
	coordinates.setPosition(level->getPlayer()->getPosition().x, level->getPlayer()->getPosition().y);
	coordinates.setString(coordinate_string);
	coordinates.setColor(sf::Color::White);
	window->draw(coordinates);
}
