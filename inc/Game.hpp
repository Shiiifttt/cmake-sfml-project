#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Player.hpp"
#include "Camera.hpp"

enum GameState {
	MainMenu,
	Play,
	Pause
};

class Game {

	Player*				player;
	Camera				camera;

	sf::RenderWindow&	window;
	sf::Clock			clock;

	//std::atomic<bool>	running(true);
	bool	initialized;
	bool	running;

	GameState gameState;

public:
	Game(sf::RenderWindow& window);
	~Game();

	sf::RenderWindow&	getWindow();
	Player*				getPlayer();
	sf::Clock&			getClock();
	Camera&				getCamera();

	void	setGameState(GameState state);
	const GameState&	getGameState();
	void	closeGame();
	void	unpause();

	bool	initSuccess();
	bool	isRunning();
	

};