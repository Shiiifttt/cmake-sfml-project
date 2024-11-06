#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Object
{

private:
	float	x;
	float	y;
	int	layer;

	sf::Texture	tex;
	sf::Sprite	spr;

	bool enabled;

public:
	Object(const float& x, const float& y, sf::Texture* tex);
	~Object();

	sf::Sprite*	getSprite();
	void	drawSprite(sf::RenderWindow& window);
	void	move(const sf::Vector2f& dir);
	virtual void	update(const float& deltaTime);
	sf::Vector2f	getPosition();

	void	enable();
	void	disable();
	bool	isEnabled();
};

