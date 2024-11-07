#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Resources.hpp"
#include <string>

Object::Object(const sf::Vector2f& position, sf::Texture* tex) : position(position), layer(1), enabled(true) {

	spr = sf::Sprite(*tex);
	spr.move(position);

	sf::Vector2 size = tex->getSize();
	spr.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	
	Resources& resources = Resources::getInstance();
	resources.registerObject(this);

}

Object::~Object() {

	Resources& resources = Resources::getInstance();
	resources.unregisterObject(this);

}

sf::Sprite*	Object::getSprite() {

	return (&spr);

}

void	Object::drawSprite(sf::RenderWindow& window) {

	window.draw(spr);

}

void	Object::update(const float& deltaTime) {

}

void	Object::move(const sf::Vector2f& dir) {

	old_position = position;
	position += dir;
	spr.setPosition(position);

}

sf::Vector2f	Object::getPosition() {

	return position;

}

void	Object::enable() {

	enabled = true;

}

void	Object::disable() {

	enabled = false;

}

bool	Object::isEnabled() {

	return enabled;

}