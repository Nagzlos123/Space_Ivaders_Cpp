#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->speed = static_cast<float>(this->pointCount / 3);
	this->damage = this->pointCount;
	this->points = this->pointCount;
	this->hpMax = static_cast<int>(this->pointCount);
	this->hp = this->hpMax;
}

void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount*5);
	this->shape.setPointCount(5);
	//this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	 // texture is a sf::Texture
	
}

void Enemy::initTexture()
{
	this->texture.loadFromFile("Textures/enemy1.png");
}

void Enemy::initSprite()
{
	this->shape.setTexture(&texture);
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initShape();

	this->initSprite();

	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int & Enemy::getPoints() const
{
	return this->points;
}

const int & Enemy::getDamage() const
{
	return this->damage;
}

//Functions
void Enemy::update()
{
	this->shape.move(0.f, 5.f);
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
