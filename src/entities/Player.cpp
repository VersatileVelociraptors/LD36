#include "Player.hpp"
#include "../level/Level.hpp"

Player::Player(){

}

Player::Player(Level *level){
	setLevel(level);
	init();
}

Player::~Player(){
	
}

void Player::setLevel(Level *level){
	this->level = level;
}

Level* Player::get_level(){
	return this->level;
}

void Player::init(){
	this->window = level->getWindow();

	this->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	set_true((int) window->getSize().x/2, (int) window->getSize().y/2);

	if(!this->texture.loadFromFile("assets/images/player.png"))
		level->getWindow()->close();
	
	this->setTexture(this->texture);

	this->diag = (int) this->speed * sqrt(2)/2;
	
	sf::IntRect texture_rect = this->getTextureRect();
	this->setOrigin(texture_rect.width/2, texture_rect.height/2);
	this->setScale(1.0f, 1.0f);
	spawn();
}

void Player::spawn(){
	xDirection=0;
	y_velocity=0;
	set_true((level->getSpawnTile().x+1)*TILE_SIZE+(PLAYER_WIDTH/2),level->getSpawnTile().y*TILE_SIZE+(PLAYER_HEIGHT/2));
}


void Player::set_true(float x, float y){
	true_x=x;
	true_y=y;
}

void Player::set_grid(){
	grid_x=(true_x/TILE_SIZE);
	grid_y=(true_y/TILE_SIZE);
}

sf::Vector2i Player::get_grid(){
	sf::Vector2i value(grid_x,grid_y);
	return value;
}

sf::Vector2i Player::get_true(){
	sf::Vector2i value(true_x,true_y);
	return value;
}


void Player::update(float dt){
	if (dimension_timer.getElapsedTime().asSeconds() > DIMENSION_CHANGE_DELAY &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {
		// change dimensions
		level->changeDimensions();
		dimension_timer.restart();
	}


	xDirection = 0;
	yDirection = 1;
	set_grid();
	
	// interact with switches
	if (currentTileType() == OFF_SWITCH_TILE &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !switchHeld){
		level->setSwitchActivated(!level->getSwitchActivated());// toggle state of switch
	}
	switchHeld = sf::Keyboard::isKeyPressed(sf::Keyboard::E);

	yDirection=0;

	// keyboard input for movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		xDirection = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		xDirection = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		yDirection = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		yDirection = 1;
	}
	
	if(xDirection==-1){
		if(level->tile_solid_grid(get_grid().x-1,get_grid().y)){
			if(true_x-PLAYER_WIDTH/2<=(get_grid().x)*TILE_SIZE){
					set_true(get_grid().x*TILE_SIZE+(PLAYER_WIDTH/2),true_y);
			}else{
				move(speed, 0);
				rot-= ((float)speed)/(PLAYER_HEIGHT/2)*180/PI;
			}
		}else{
			rot-= ((float)speed)/(PLAYER_HEIGHT/2)*180/PI;
			move(speed,0);
		}
	}else if(xDirection==1){
		if(level->tile_solid_grid(get_grid().x+1,get_grid().y)){
			if(true_x+PLAYER_WIDTH/2>=(get_grid().x+1)*TILE_SIZE){
					set_true(get_grid().x*TILE_SIZE+(PLAYER_WIDTH/2),true_y);
			}else{
				move(-speed, 0);
				rot+= ((float)speed)/(PLAYER_HEIGHT/2)*180/PI;
			}
			
		}else{
			move(-speed,0);
			rot+= ((float)speed)/(PLAYER_HEIGHT/2)*180/PI;
		}
	}


	if(!jump && yDirection==-1 && y_velocity==0){
		y_velocity = 16;
		jump=true;
		total_time=5;
		level->getSoundManager()->play("jump");
	}

	{
		if(y_velocity>0){
			
			if(level->tile_solid_grid(get_grid().x,get_grid().y-1)){
				if(true_y-PLAYER_WIDTH/2-y_velocity<=(get_grid().y)*TILE_SIZE){
					y_velocity=0;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else
			if(level->tile_solid_grid(get_grid().x+1,get_grid().y-1)){
				if(true_y-PLAYER_WIDTH/2-y_velocity<=(get_grid().y)*TILE_SIZE && true_x+PLAYER_WIDTH/2>(get_grid().x+1)*TILE_SIZE){
					y_velocity=0;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else
			if(level->tile_solid_grid(get_grid().x-1,get_grid().y-1)){
				if(true_y-PLAYER_WIDTH/2-y_velocity<=(get_grid().y)*TILE_SIZE && true_x-PLAYER_WIDTH/2<(get_grid().x)*TILE_SIZE){
					y_velocity=0;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else{
				move(0,y_velocity);
			}

		}else{
			if(level->tile_solid_grid(get_grid().x,get_grid().y+1)){
				if(true_y+PLAYER_WIDTH/2-y_velocity>=(get_grid().y+1)*TILE_SIZE){
					y_velocity=0;
					jump=false;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else if(level->tile_solid_grid(get_grid().x+1,get_grid().y+1)&& true_x+PLAYER_WIDTH/2>(get_grid().x+1)*TILE_SIZE){
				if(true_y+PLAYER_WIDTH/2-y_velocity>=(get_grid().y+1)*TILE_SIZE){
					y_velocity=0;
					jump=false;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else if(level->tile_solid_grid(get_grid().x-1,get_grid().y+1)){
				if(true_y+PLAYER_WIDTH/2-y_velocity>=(get_grid().y+1)*TILE_SIZE&& true_x-PLAYER_WIDTH/2<get_grid().x*TILE_SIZE){
					y_velocity=0;
					jump=false;
					set_true(true_x,get_grid().y*TILE_SIZE+(PLAYER_HEIGHT/2));
				}else{
					move(0, y_velocity);
				}
			}else{
				move(0,y_velocity);
			}

		}
		
		if(total_time==5){
			y_velocity-=4;
			total_time=0;
		}
		total_time++;
	}




	setRotation(rot);



	if(currentTileType() == DEATH_TILE){
		spawn();
		level->setChangedDimension(false);
		level->setSwitchActivated(false);
	} else if (currentTileType() == END_TILE) {
		level->nextLevel();
		spawn();
		level->setChangedDimension(false);
		level->setSwitchActivated(false);
	}
	//WE ARE ALL SO FUCKING STUPID


	level->setXOffset(getPosition().x - get_true().x);
	level->setYOffset(getPosition().y - get_true().y);
}

void Player::move(float x, float y){
	set_true(get_true().x-x, get_true().y-y);
}

/// type of tile under the player
int Player::currentTileType(){
	return level->tile_type_grid(get_grid().x, get_grid().y);
}
