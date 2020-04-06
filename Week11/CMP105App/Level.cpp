#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	//audio->addMusic("sfx/cantina.ogg", "cantina");


	pTexture.loadFromFile("gfx/Mushroom.png");
	player.setTexture(&pTexture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 100);
	player.setInput(input);


	gameState->setCurrentState(State::MENU);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		gameState->setCurrentState(State::LEVEL);
	}
	



	switch (gameState->getCurrentState())
	{
	case (State::MENU):
		menu.handleInput(dt);

	break;

	case (State::LEVEL):
		level1.handleInput(dt);
		player.handleInput(dt);

	}
}

// Update game objects
void Level::update(float dt)
{


	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	//menu.render();
	window->draw(player);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}