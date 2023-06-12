#include "Game.h"
#include "Enemy.h"

using namespace sf;
using namespace std;

void Game::initVar()
{
	this->window = nullptr;

	this->points = 0;
	//this->enemySpawnTimerMax = 30.f;
	//this->enemySpawnTimer = this->enemySpawnTimerMax;

	this->enemyMaxNumber = 20;
	this->mouseHeld = false;
}
void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(800, 600), "Sace Invaders!", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer() {

	this->player = new Player();
	
}

void Game::initEnemies()
{
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
}

void Game::initTextures() {

	this->textures["BULLET"] = new Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("fonts_windows/arial.ttf"))
		std::cout << "Failed to load font" << "\n";

	//Init point text
	this->pointText.setPosition(600.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(24);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
	this->initGUI();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//delete textures	
	for (auto& i : this->textures) {
		delete i.second;
	}
	//delete bullets	
	for (auto* i : this->bullets) {
		delete i;
	}

	//Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}
}



//metoda dostepu
const bool Game::running() const {
	return this->window->isOpen();

}

void Game::updateMousePositions()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{

	

	//Update
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//Enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}


	/*
	if (this->enemies.size() < this->enemyMaxNumber)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}
	
	//poruszanie i odswiezanie
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		if (enemies[i].shape.getPosition().x <= 0)
		{
			//this->enemies[i].setPosition(0.f, this->enemies[i].getPosition().y);
			
		}
		else if (this->enemies[i].shape.getPosition().x >= window->getSize().x - this->enemies[i].shape.getGlobalBounds().width)
		{
			//this->enemies[i].setPosition(window->getSize().x - this->enemies[i].getGlobalBounds().width, this->enemies[i].getPosition().y);
			this->enemies[i].shape.move(-1.f, 0.f);
		}

		this->enemies[i].shape.move(1.f, 0.f);
		
		//sprwdzanie czy klikniete
		
			if (this->enemies[i].shape.getGlobalBounds().contains(this->mousePosView))
			{
				deleted = true;

				//punkty
				this->points += 10.f;

			}
		

		if (this->enemies[i].shape.getPosition().x > this->window->getSize().x)
		{

		}

		if (deleted)
			this->enemies.erase(this->enemies.begin() + 1);
	}
	*/
}


void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->pointText.setString(ss.str());

	//Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
}

void Game::spawnEnemy()
{
	

	//Spawning
	this->enemySpawnTimer += 0.5f;
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
		this->enemySpawnTimer = 0.f;
	}
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->event.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateShot() {

	if (Keyboard::isKeyPressed(Keyboard::Up) && this->player->canAttack()) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f));
	}
}

void Game::updateBullets() {

	unsigned counter = 0;

	for (auto* bullet : this->bullets) {

		bullet->update();

		//bullet culling (top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}

}



//Funkcje
void Game::update()
{
	this->pollEvents();


	this->updateMousePositions();
	this->spawnEnemy();

	this->updateEnemies();
	this->updateGUI();
	this->updateShot();
	this->updateBullets();
	this->updateCombat();


	this->player->update(this->window);
}

void Game::renderEnemies()
{
	//Renderowanie przeciwników
	
		
	
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::render()
{
	this->window->clear();

	this->renderEnemies();

	this->player->render(this->window);

	for (auto* bullet : this->bullets) {

		bullet->render(this->window);
	}

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderGUI();
	//this->enemy->render(this->window);
	this->window->display();
}




