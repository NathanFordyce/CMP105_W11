#include "Player.h"
Player::Player()
{
	audioMgr.addSound("sfx/smb_jump-small.ogg", "jump");
	audioMgr.addSound("sfx/Glass_Break.ogg", "break");

	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8) * scale;

	jumpVector = sf::Vector2f(0, -5.f) * scale;
	isJumping = false;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	//Check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			audioMgr.playSoundbyName("jump");
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		speedX = 200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		speedX = -200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}
}

void Player::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; // v = u + at
	setPosition(getPosition() + pos);

	//Check for collision with floor
	if (getPosition().y >= 575)
	{
		isJumping = false;
		setPosition(getPosition().x, 575);
		stepVelocity = sf::Vector2f(0, 0);
	}

	if (getPosition().x <= 0)
	{
		audioMgr.playSoundbyName("break");
		setPosition(0, getPosition().y);
	}
	else if (getPosition().x >= 1100)
	{
		audioMgr.playSoundbyName("break");
		setPosition(1100, getPosition().y);
	}
}

