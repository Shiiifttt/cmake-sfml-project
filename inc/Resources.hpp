#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.hpp"
#include "IDamage.hpp"

class Resources {

	static const std::string	player_spr;
	static const std::string	enemy_spr;
	static const std::string	bullet_spr;
	static const std::string	font_ttf;
	static const std::string	hit_wav;
	static const std::string	explode_wav;



	sf::Font	font;
	sf::Texture	player_tex;
	sf::Texture	enemy_tex;
	sf::Texture	bullet_tex;

	sf::SoundBuffer	hit_sfx;
	sf::SoundBuffer	explode_sfx;

	std::vector<Object*>	scene_objects;
	std::vector<IDamage*>	damage_interfaces;

	sf::Sound	soundBuffer[4];
	int			soundBufferIndex;

public:

	static Resources&		getInstance() {
		static Resources instance;
		return instance;
	};

	Resources();
	Resources(const Resources& r) = delete;
	Resources& operator=(const Resources& r) = delete;
	~Resources();

	bool			loadResources();
	sf::Texture*	getPlayerTex();
	sf::Texture*	getEnemyTex();
	sf::Texture*	getBulletTex();
	sf::Font*		getFont();

	void					registerObject(Object* obj);
	void					unregisterObject(Object* obj);
	void					registerDamageInterface(IDamage* interface);
	void					unregisterDamageInterface(IDamage* interface);

	void					clean();
	std::vector<Object*>	getSceneObjects();
	std::vector<IDamage*>	getDamageInterfaces();

	void	playSound(const sf::SoundBuffer& buffer);
	void	playHitSound();
	void	playExplodeSound();

};