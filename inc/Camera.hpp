
#pragma once

#include <SFML/Graphics.hpp>

class Camera {

	sf::Vector2f	view_size;
	sf::Vector2f	position;

	float	frustrum_width;
	float	frustrum_height;

public:

	Camera(const sf::Vector2f& view_size, const float& frustum_size);
	bool	pointInsideView(const sf::Vector2f& point);
	void	setPosition(const sf::Vector2f& point);

};