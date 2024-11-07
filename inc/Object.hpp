#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Object
{

private:
	sf::Vector2f	position;
	sf::Vector2f	old_position;
	int		layer;

	sf::Texture	tex;
	sf::Sprite	spr;

	bool enabled;

public:
	Object(const sf::Vector2f& position, sf::Texture* tex);
	~Object();

	sf::Sprite*		getSprite();
	void			drawSprite(sf::RenderWindow& window);
	void			move(const sf::Vector2f& dir); // move to IMovement
	virtual void	update(const float& deltaTime);
	sf::Vector2f	getPosition();

	void	enable();
	void	disable();
	bool	isEnabled();
};

