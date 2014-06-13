#include "Game.h"

using namespace std;
using namespace sf;

Game::Game(void): window (RenderWindow(VideoMode(1920, 1080), "TileMapTest", Style::Default))
{
	window.setFramerateLimit(60);
	fileName = "Texture_Tetris.png";
	width = 4;
	height = 4;
	tileSize = Vector2f(100, 100);
	shape[0] = 1;
	shape[1] = 0;
	shape[2] = 0;
	shape[3] = 0;
	shape[4] = 1;
	shape[5] = 0;
	shape[6] = 0;
	shape[7] = 0;
	shape[8] = 1;
	shape[9] = 0;
	shape[10] = 0;
	shape[11] = 0;
	shape[12] = 1;
	shape[13] = 0;
	shape[14] = 0;
	shape[15] = 0;
	createScene();
}

void Game::run()
{
	while (window.isOpen())
	{
		entries();
		update();
		render();
	}
}

void Game::entries()
{
	while (window.pollEvent(event))
	{
		if(event.type == Event::Closed)
		{
			window.close();
		}
		if(event.type == Event::KeyPressed)
		{
			if(event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}

void Game::update()
{
	//rect.move(0, 1);
}

void Game::createScene()
{
	rect = RectangleShape(Vector2f(100, 20));
	rect.setFillColor(Color(255, 255, 0));
	rect.setPosition(910,0);

	if(!shapes.load(fileName, width, height, shape, tileSize))
		cout << "Error, during the file's loading" << endl;
}

void Game::draw()
{
	//window.draw(rect);
}

void Game::render()
{
	window.clear();
	draw();
	window.display();
}