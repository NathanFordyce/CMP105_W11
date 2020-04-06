#pragma once
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include <iostream>

class Player: public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;

	float speedX;
	float speedY;

	//sf::RenderWindow* window;


	AudioManager audioMgr;

	//Gravity vectors and variables
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;
};

