#pragma once
#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"
#include <iostream>

class Menu:
	public GameObject
{
public:
	Menu();
	~Menu();

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

