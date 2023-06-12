#pragma once


#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;


class Player
{
private:
	RectangleShape shape;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax; 

	void initVariables();
	void initShape();

	Sprite sprite; 
	Texture texture; 

	int hp;
	int hpMax;

	void initTexture(); 
	void initSprite(); 

public:
	Player(float x = 390.f, float y = 510.f);
	virtual ~Player();

	//Accessor
	const Vector2f& getPos() const; 
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	const bool canAttack(); 
	void setHp(const int hp);
	void loseHp(const int value);

	void updateInput();
	void updateAttack(); 
	void updateWindowBoundsCollision(const RenderTarget* target);
	void update(const RenderTarget* target);
	void render(RenderTarget* target);
};
