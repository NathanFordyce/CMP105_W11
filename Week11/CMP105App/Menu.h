#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Menu : public GameObject
{
public:
	Menu();
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render(sf::RenderWindow* hwnd);

	sf::Text text;
	sf::Font font;

	sf::RenderWindow* window;
};

