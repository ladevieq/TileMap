#include "TileMap.h"

using namespace std;
using namespace sf;

bool TileMap::load(string tile, int width, int height, const int* tiles, Vector2f tileSize)
{
	if(!m_tile.loadFromFile(tile))
		cout << "Connard" << endl;

	m_vertices.setPrimitiveType(Quads);
	m_vertices.resize(width * height);

	for(int i = 0; i < width; i ++)
		for(int j = 0; j < height; i ++)
		{
			int tileNumber = tiles[i + j];

			float tu = tileNumber % m_tile.getSize().x / tileSize.x;
			float tv = tileNumber / (m_tile.getSize().x / tileSize.x);

			sf::Vertex *quad = &m_vertices[i + j * width];

			quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	return true;
}