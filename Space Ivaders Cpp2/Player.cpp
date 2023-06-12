#include "Player.h"


#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

void Player::initTexture() { 

	this->texture.loadFromFile("Textures/ship1.png");
	
}

void Player::initSprite() { 

	this->sprite.setTexture(this->texture);

	// this->sprite.scale(1.f, 1.f); //na razie u¿ywamy domyœlnej wielkoœci
}

void Player::initVariables() {

	this->movementSpeed = 5.f;
	this->attackCooldownMax = 10.f; 
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;

}

void Player::initShape() {

	this->shape.setFillColor(Color::Blue);
	this->shape.setSize(Vector2f(50.f, 25.f));

}

Player::Player(float x, float y) {

	this->sprite.setPosition(x, y); // 03.01 (by³o wczeœniej "shape")

	this->initVariables();
	//this->initShape();

	this->initTexture();
	this->initSprite(); 
}

Player::~Player() {
	

}

void Player::updateInput() {

	//keyboard
	//left
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		this->sprite.move(-this->movementSpeed, 0.f); 
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		this->sprite.move(this->movementSpeed, 0.f); 
	}
}

void Player::updateWindowBoundsCollision(const RenderTarget* target) {

	FloatRect playerBounds = this->sprite.getGlobalBounds(); 
	if (playerBounds.left <= 0.f)
		this->sprite.setPosition(0.f, playerBounds.top);		
	if (playerBounds.left + playerBounds.width >= target->getSize().x)
		this->sprite.setPosition(target->getSize().x - playerBounds.width, playerBounds.top); 

}

const Vector2f& Player::getPos() const { 

	return this->sprite.getPosition();

}


const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int & Player::getHp() const
{
	return this->hp;
}

const int & Player::getHpMax() const
{
	return this->hpMax;
}

const bool Player::canAttack() { 

	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack() { 

	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;

}


void Player::update(const RenderTarget* target) {

	this->updateInput();
	//window bounds collision
	this->updateWindowBoundsCollision(target);

	this->updateAttack(); 
}

void Player::render(RenderTarget* target) {

	//target->draw(this->shape);

	target->draw(this->sprite); 
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}