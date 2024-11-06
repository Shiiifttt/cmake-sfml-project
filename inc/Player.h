#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "IMovement.h"

class Player : public Object, public IMovement
{
	float	shootInterval;
	float	shootTimer;
	int		bulletDamage;
	
	int	face_dir;

public:
	Player(const float& x, const float& y, sf::Texture* tex, const float& movespeed);
	void	input(const float& deltaTime);
	void	shoot();

	void	update(const float& deltaTime) override;

};

