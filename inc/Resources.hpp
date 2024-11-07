#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Resources {

	static const std::string	player_spr;
	static const std::string	enemy_spr;
	static const std::string	bullet_spr;
	static const std::string	font_ttf;

	sf::Font	font;
	sf::Texture	player_tex;
	sf::Texture	enemy_tex;
	sf::Texture	bullet_tex;

	std::vector<Object*>	scene_objects;

	std::map<std::pair<int,int>, std::vector<Object*>>	world_grid;

	int	partitions = 4;
	int	partition_width;
	int	partition_height;

public:

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
	void					clean();
	std::vector<Object*>	getSceneObjects();

	static Resources&		getInstance() {
		static Resources instance;
		return instance;
	};

};