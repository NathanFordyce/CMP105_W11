#pragma once
#include "Framework/GameObject.h"
class Menu:
	public GameObject
{
public:
	Menu();
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

};

