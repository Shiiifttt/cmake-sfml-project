#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"
#include <string>

Object::Object(const float& x, const float& y, sf::Texture* tex) : x(x), y(y), layer(1), enabled(true) {
	spr = sf::Sprite(*tex);
	spr.move(sf::Vector2f(x, y));

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
	x += dir.x;
	y += dir.y;
	spr.move(dir);
}

sf::Vector2f	Object::getPosition() {
	return sf::Vector2f(x, y);
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