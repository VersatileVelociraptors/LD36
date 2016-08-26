#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "AudioManager.h"

#include <vector>
#include <string>

class SoundManager : public AudioManager 
{
public:
	SoundManager(sf::RenderWindow *window);
	~SoundManager();

	void addAllSoundInAssets();
	void addSound(std::string name, sf::SoundBuffer sound_buffer);
	void addSound(std::string name, char* path);
	void play(std::string name);
	void loop(std::string name);
	void stop(std::string name);
	void stop();
	std::vector<std::string> getSoundsNames();
	std::vector<sf::SoundBuffer*> getSounds();
};

#endif