#include "Menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	audioMgr.addMusic("sfx/Cantina.ogg", "cantina");

	audioMgr.playMusicbyName("cantina");

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

void Menu::render()
{
	window->draw(text);

}