#pragma once
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <iostream>

class Screen :
	public GameObject
{
public:
	Screen();
	~Screen();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

	sf::Font font;
	sf::Text text;

	GameState* gameState;
	AudioManager audioMgr;

private:
	sf::RenderWindow* window;
};