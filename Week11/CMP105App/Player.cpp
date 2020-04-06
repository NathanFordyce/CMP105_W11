#include "Player.h"
Player::Player()
{
	audioMgr.addSound("sfx/Glass_Break.ogg", "break");

	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	speedX = 0;
	speedY = 0;

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		std::cout << "test";

		speedX = 200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		speedX = -200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		speedY = 200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		speedY = -200;
		setVelocity(speedX, speedY);
		move(getVelocity() * dt);
	}
	
	//Check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		std::cout << "test";

		if (!isJumping)
		{
			std::cout << "test";
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

}

void Player::update(float dt)
{

	if ((getPosition().y + 100) > 700)
	{
		audioMgr.playSoundbyName("break");
	}
	else if ((getPosition().x + 100) > 1200)
	{
		audioMgr.playSoundbyName("break");
	}
	else if ((getPosition().y) < 0)
	{
		audioMgr.playSoundbyName("break");
	}
	else if ((getPosition().x) < 0)
	{
		audioMgr.playSoundbyName("break");
	}

	//Gravity
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
}