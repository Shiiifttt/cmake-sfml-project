#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "IMovement.hpp"

class Player : public Object, public IMovement
{
	float	shootInterval;
	float	shootTimer;
	int		bulletDamage;
	
	int	face_dir;

public:
	Player(const sf::Vector2f& position, sf::Texture* tex, const float& movespeed);

	void	update(const float& deltaTime) override;
	void	input(const float& deltaTime);
	void	shoot();

};

