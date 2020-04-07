#pragma once
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;

	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;

	float speedX = 0;
	float speedY = 0;

	AudioManager* audio;

	AudioManager audioMgr;

};

