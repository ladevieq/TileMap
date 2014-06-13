#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"

class Game
{
public:
	Game();

	void run();

	void entries();

	void update();

	void createScene();

	void draw();

	void render();

private:
	sf::RenderWindow window;

	sf::Event event;

	sf::RectangleShape rect;

	TileMap shapes;

	std::string fileName;
	int width, height;
	sf::Vector2f tileSize;

	int shape[16];
};

