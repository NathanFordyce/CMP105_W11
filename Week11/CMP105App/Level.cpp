#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	audio->addMusic("sfx/cantina.ogg", "cantina");

	pTexture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&pTexture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(0, 0);
	player.setInput(input);

	gameState->setCurrentState(State::MENU);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter) && gameState->getCurrentState() == State::MENU)
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::LEVEL);
		audio->playMusicbyName("cantina");

	}

	if (input->isKeyDown(sf::Keyboard::Enter) && gameState->getCurrentState() == State::LEVEL)
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::MENU);
		player.setPosition(0, 0);
		audio->stopAllMusic();
	}

	if (input->isKeyDown(sf::Keyboard::Escape) && gameState->getCurrentState() == State::LEVEL)
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::PAUSE);
	}

	if (input->isMouseLDown() && gameState->getCurrentState() == State::PAUSE)
	{
		gameState->setCurrentState(State::LEVEL);
	}

	switch (gameState->getCurrentState())
	{
	case (State::MENU):
		menu.handleInput(dt);
		break;

	case (State::LEVEL):
		game.handleInput(dt);
		player.handleInput(dt);
		break;

	case (State::PAUSE):
		pause.handleInput(dt);
		break;
	}
}

// Update game objects
void Level::update(float dt)
{
	switch (gameState->getCurrentState())
	{
	case (State::MENU):
		menu.update(dt);
		break;

	case (State::LEVEL):
		game.update(dt);
		player.update(dt);
		break;
	}
}

// Render level
void Level::render()
{
	beginDraw();

	switch (gameState->getCurrentState())
	{
	case (State::MENU):
		menu.render(window);
		break;

	case (State::LEVEL):
		game.render(window);
		window->draw(player);
		break;

	case (State::PAUSE):
		pause.render(window);
		break;
	}

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