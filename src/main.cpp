#define SFML_STATIC

#include <SFML/Graphics.hpp>

#include "states/GameStateManager.hpp"
#include "audio/SoundManager.hpp"
#include "level/Level.hpp"
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720
#define TITLE "LD36 Test"

void update(GameStateManager* manager, sf::Text fps, sf::Text ups, bool *doUpdate, double dt){

	if(*doUpdate){
	 //manager->update(dt);
	 *doUpdate = false;
	}

	manager->getWindow()->clear();
	//manager->render();
	manager->getWindow()->draw(fps);
	manager->getWindow()->draw(ups);
	manager->getWindow()->display();
}

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(false);
	GameStateManager manager(&window);

	sf::Font font;
	if (!font.loadFromFile("assets/fonts/arial.ttf"))
		window.close();


	sf::Clock clock;
	sf::Time fpsLastTime;
	float FPS = 0;
	int frames = 0;
	
	sf::Time upsLastTime;
	sf::Time currentTime;
	int updates = 0;
	int UPS = 0;
	bool doUpdate = false;
	double MS = 1000000.0 / 60.0;
	double dt = 0;

	while(window.isOpen()){
		sf::Event event;

		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		currentTime = clock.getElapsedTime();
		if(currentTime.asMilliseconds() - fpsLastTime.asMilliseconds() >= 1000){
			FPS = (float) frames / (currentTime.asSeconds() - fpsLastTime.asSeconds());
			fpsLastTime = currentTime;
			frames = 0;

			UPS = updates;
			updates = 0; 
		}

		dt += currentTime.asMicroseconds() - upsLastTime.asMicroseconds();
		upsLastTime = currentTime;

		if(dt >= MS){
			doUpdate = true;
			updates++;
		}

		sf::Text fps;
		char fps_text[15];
		sprintf(fps_text, "%.1f FPS", FPS);
		fps.setFont(font);
		fps.setCharacterSize(24);
		fps.setString(fps_text);
		fps.setColor(sf::Color::White);

		sf::Text ups;
		char ups_text[15];
		sprintf(ups_text, "%i UPS", UPS);
		ups.setFont(font);
		ups.setCharacterSize(24);
		ups.setPosition(0, 30);
		ups.setString(ups_text);
		ups.setColor(sf::Color::White);

		update(&manager, fps, ups, &doUpdate, dt);
		if(dt >= MS) 
			dt -= MS;
		frames++;
	}
	manager.getMusicManager()->stop();

	return 0;
}