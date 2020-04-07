#pragma once
#include "Framework/GameObject.h"
#include <iostream>

class Pause : public GameObject
{
public:
	Pause();
	~Pause();

	void handleInput(float dt) override;
	void render(sf::RenderWindow* hwnd);


};

