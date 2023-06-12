#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemy
{
public:
	CircleShape shape;

	Enemy(float pos_x, float pos_y);
	

	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);

	

private:


	unsigned pointCount;
	float speed;
	int damage;
	int points;
	void initVariables();
	void initShape();

	Sprite sprite;
	Texture texture;

	int hp;
	int hpMax;
	

	void initTexture();
	void initSprite();

};






