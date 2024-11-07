#include "Utils.hpp"
#include <cmath>

sf::Vector2f	normalize(const sf::Vector2f& vector) {

	float	len = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	if (len != 0)
		return (sf::Vector2f(vector.x / len, vector.y / len));

	return vector;
}

float	distance(const sf::Vector2f& a, const sf::Vector2f& b) {

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

}

sf::Text	newText(sf::Vector2f pos, const std::string& str, sf::Font* font, int size, sf::Color color, sf::Uint32 style, font_align align) {

	sf::Text text;

	text.setFont(*font);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	sf::FloatRect bounds = text.getGlobalBounds();

	if (align & font_align::H_CENTER) {
		pos.x -= bounds.width / 2.f;
		pos.y -= bounds.height / 2.f;
	}
	 else if (align & font_align::H_RIGHT) {
		pos.x -= bounds.width;
	}

	text.setPosition(sf::Vector2f(pos.x, pos.y));

	return text;

}
