#include "Screen.h"

Screen::Screen()
{
	audioMgr.addMusic("sfx/Cantina.ogg", "cantina");
	audioMgr.addSound("sfx/SMB_jump-small.ogg", "jump");
	audioMgr.addSound("sfx/SMB_1-up.ogg", "up");

}

Screen::~Screen()
{

}

void Screen::handleInput(float dt)
{
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

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		audioMgr.playMusicbyName("cantina");
	}
}

void Screen::update(float dt)
{

}

void Screen::render()
{

}