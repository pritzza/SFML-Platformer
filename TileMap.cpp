#include "TileMap.h"

#include "BlockTile.h"
#include "AirTile.h"
#include "Constants.h"

#include <iostream>

TileMap::TileMap(unsigned width, unsigned height, int level)
{
	gridSizeU = static_cast<unsigned>(gridSizeF);
	maxSize.x = width;
	maxSize.y = height;
	layers = 1;

	for (size_t x = 0; x < maxSize.x; ++x)
	{
		map.push_back(std::vector < std::vector<Tile*> >());

		for (size_t y = 0; y < maxSize.y; ++y)
		{
			map[x].push_back(std::vector<Tile*>());
		
			for (size_t z = 0; z < layers; ++z)
			{
				map[x][y].push_back(getTileMap(x, y, level));
			}
		}
	}

	std::cout << "AFTER CONSTRUCTION : map.size() = " << map.size() << " map[0].size() = " << map[0].size() << " map[0][0].size() = " << map[0][0].size();
}

TileMap::~TileMap()
{
	clear();	// pretty sure this isnt being called ever
}

Tile* TileMap::getTileMap(int x, int y, int level)
{
	int levelWidth;
	int levelHeight;

	switch (level)
	{
	default:

		char testLevel[12][16] { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ','x',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ',' ',' ',' ',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								 ' ',' ',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',
								 ' ',' ',' ','x','x','x',' ','x','x','x','x','x','x',' ',' ',' ',
								 ' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',
								 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
								 'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x', };

		return getTile(x, y, testLevel[y][x]);

		break;
	}
}

Tile* TileMap::getTile(int x, int y, char id)
{
	switch (id)
	{
	case (' '):
		return new AirTile(x, y, gridSizeF);
		break;

	case ('x'):
		return new BlockTile(x, y, gridSizeF);
		break;

	default:
		return new Tile(x, y, gridSizeF);
		break;
	}
}

void TileMap::clear()
{
	for (size_t x = 0; x < maxSize.x; ++x)
	{
		for (size_t y = 0; y < maxSize.y; ++y)
		{
			for (size_t z = 0; z < layers; ++z)
			{
				delete map[x][y][z];
			}
		}
	}

	//std::cout << "AFTER CLEAR() : map.size() = " << map.size() << " map[0].size() = " << map[0].size() << " map[0][0].size() = " << map[0][0].size();

}

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget& target, sf::Vector2i camera)
{
	//for (int x = player.x - 1; x <= player.x + 1; ++x)
	//{
	//	std::cout << "X: " << x << std::endl;
	//	for (int y = player.y - 1; y <= player.y + 1; ++y)
	//	{
	//		std::cout << "Y: " << y << std::endl;
	//		for (int z = 0; z < layers; ++z)
	//		{
	//			std::cout << "Z: " << z << std::endl;
	//			map[x][y][z]->render(target);
	//		}
	//	}
	//}

	for (auto& x : map)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				z->render(target);
			}
		}
	}
}