#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	bool jumpFlag { false };
	bool leftFlag{ false };
	bool rightFlag{ false };
	bool sprintFlag{ false };
	int direction{ 0 };

	//add some kinda jump counter
	const int maxJumpFrames{ 12 };
	int jumpFrameIndex{ 0 };

	const float sprintSpeed{ 2.0f };
	const float walkSpeed{ 1.0f };

public:
	Player(std::vector<Entity*>& entities) : Entity{ entities } {};
	~Player();

	void init(AssetManager* assets);

	void update(TileMap* t, sf::Text& debugText);

	void jump();
	void move();
	void toggleSprint();

	void handleInput(char input);
};