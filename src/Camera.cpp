
#include <SFML/Graphics.hpp>
#include "Camera.hpp"

Camera::Camera(const sf::Vector2f& view_size, const float& frustrum) : view_size(view_size), frustrum_width(view_size.x + frustrum), frustrum_height(view_size.y + frustrum) {

}

bool	Camera::pointInsideView(const sf::Vector2f& point) {
	
	if ((point.x >= (position.x - frustrum_width / 2))
		&& (point.x <= (position.x + frustrum_width / 2))
		&& (point.y >= (position.y - frustrum_height / 2))
		&& (point.y <= (position.y + frustrum_height / 2)))
		return true;

	return false;
}

void	Camera::setPosition(const sf::Vector2f& point) {
	position = point;
}