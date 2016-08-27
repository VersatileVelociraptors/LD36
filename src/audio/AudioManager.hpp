#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <unordered_map>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class AudioManager
{
public:
	AudioManager();
	AudioManager(sf::RenderWindow *window);
	~AudioManager();

protected:

	struct Sounds{
		Sounds(sf::SoundBuffer *sb, sf::Sound *sound){
			this->sb = sb;
			this->sound = sound;
		}
		~Sounds(){
			delete sb;
			delete sound;
		}
		sf::SoundBuffer *sb;
		sf::Sound *sound;
	};

	std::unordered_map<std::string, sf::Music*> *musics;
	std::unordered_map<std::string, Sounds*> *sounds;

	static constexpr char* ASSETS_MUSIC_PATH = (char *) "assets/music/";
	static constexpr char* ASSETS_SOUND_PATH = (char *) "assets/sound/";

	sf::RenderWindow *window;

	
};

#endif //AUDIOMANAGER_HPP