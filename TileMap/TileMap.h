#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, sf::Transformable
{
public:
	bool load(std::string tile, int width, int height, const int* tiles, sf::Vector2f tileSize);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tile;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

	sf::VertexArray m_vertices;
	sf::Texture m_tile;
};

