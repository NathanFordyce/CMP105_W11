#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	//audio->addMusic("sfx/cantina.ogg", "cantina");
	audioMgr.addMusic("sfx/Cantina.ogg", "cantina");
	audioMgr.addSound("sfx/SMB_jump-small.ogg", "jump");
	audioMgr.addSound("sfx/SMB_1-up.ogg", "up");

	pTexture.loadFromFile("gfx/Mushroom.png");
	player.setTexture(&pTexture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 100);
	player.setInput(input);

	enum class GameState { Start, Level };


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

	if (input->isKeyDown(sf::Keyboard::Num1))
	{
		input->setKeyUp(sf::Keyboard::Num1);
		audioMgr.playSoundbyName("jump");
	}

	if (input->isKeyDown(sf::Keyboard::Num2))
	{
		input->setKeyUp(sf::Keyboard::Num2);
		audioMgr.playSoundbyName("up");
	}

	if (input->isKeyDown(sf::Keyboard::Num3))
	{
		input->setKeyUp(sf::Keyboard::Num3);
		audioMgr.stopAllMusic();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	/*
	if (audioMgr.getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audioMgr.playMusicbyName("cantina");
	}
	*/

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