#pragma once

#include "GameState.h"

#include <vector>

class MenuState : public GameState
{
public:
	//World w
	//Player p

public:
	MenuState(GameData* data, sf::RenderWindow* window);
	~MenuState();

	void init();
	void terminate();

	void handleInput();
	void update();
	void draw();
};