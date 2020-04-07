#include "Menu.h"
Menu::Menu()
{
	//Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}

	text.setFont(font);
	text.setString("Main Menu \nPress ENTER to start game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(200, 200);
}

Menu::~Menu()
{

}

void Menu::handleInput(float dt)
{

}

void Menu::update(float dt)
{

}

void Menu::render(sf::RenderWindow* window)
{
	window->draw(text);
}