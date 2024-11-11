#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Resources.hpp"
#include "Camera.hpp"
#include "Utils.hpp"
#include "Enemy.hpp"

Game::Game(sf::RenderWindow& window) : window(window), gameState(GameState::Play), camera(Camera(sf::Vector2f(800, 600), 128)), initialized(false), player(nullptr), running(true) {

	Resources& resources = Resources::getInstance();
	if (!resources.loadResources())
		return;

	camera.setPosition(sf::Vector2f(400, 300));

	player = new Player(sf::Vector2f(400, 300), resources.getPlayerTex(), 200.f);

	initialized = true;

}

Game::~Game() {

	Resources& resources = Resources::getInstance();
	//resources.clean();

}

void	Game::setGameState(GameState state) {
	gameState = state;
}

const GameState&	Game::getGameState() {
	return gameState;
}

void	Game::closeGame() {
	running = false;
	window.close();
}

bool	Game::initSuccess() {
	return initialized;
}

Player* Game::getPlayer() {
	return player;
}

Camera& Game::getCamera() {
	return camera;
}

sf::RenderWindow& Game::getWindow() {
	return window;
}

sf::Clock& Game::getClock() {
	return clock;
}

bool	Game::isRunning() {
	return running;
}

void	Game::unpause() {
	clock.restart().asSeconds();
}