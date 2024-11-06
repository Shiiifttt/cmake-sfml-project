#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

enum font_align : int {
	H_LEFT = 1,
	H_CENTER = 2,
	H_RIGHT = 4,
};

sf::Vector2f	normalize(const sf::Vector2f& vector);
float	distance(const sf::Vector2f& a, const sf::Vector2f& b);
sf::Text	newText(sf::Vector2f pos, const std::string& str, sf::Font* font, int size, sf::Color color, sf::Uint32 style, font_align align);