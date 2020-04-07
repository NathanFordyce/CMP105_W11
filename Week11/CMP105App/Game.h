#pragma once
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include "Player.h"

class Game : public GameObject
{
public:
	Game();
	~Game();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render(sf::RenderWindow* hwnd);

	AudioManager audioMgr;

	Player player;
};