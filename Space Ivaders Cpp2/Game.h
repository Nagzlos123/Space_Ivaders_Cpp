#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "objects\button.hpp"
#include "objects\textbox.hpp"

#include "Player.h"
#include "Bullet.h" 
#include "Enemy.h" 

using namespace sf;
using namespace std;

class Game
{
private:
	RenderWindow* window;
	VideoMode videoMode;
	Event event;

	map <string, Texture*> textures;
	vector <Bullet*> bullets;
	//GUI
	RectangleShape playerHpBar;
	RectangleShape playerHpBarBack;
	Font font;
	Text pointText;
	Text gameOverText;
	//prywatne funkcje
	void initVar();
	void initWindow();
	void initGUI();
	void initEnemies();
	void initPlayer();
	void initTextures();

	//logika gry
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int enemyMaxNumber;
	unsigned points;
	bool mouseHeld;

	// Obiekty
       //Enemy *enemy;
	vector<Enemy*> enemies;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	

	Player * player; // 02.01 - dodany wskaünik

	//Sprite sprite;
	//Texture texture;

	

public:
	Game();
	virtual ~Game();

	//metoda dostepu
	const bool running() const;

	//Funkcje
	void spawnEnemy();
	void pollEvents();
	void updateGUI();
	void updateMousePositions();
	void updateEnemies();
	void updateBullets();
	void update();
	void updateShot();
	void renderGUI();
	void renderEnemies();
	void render();
	
	
	
	void updateCombat();
	//void initTexture();
	//void initSprite();

	

};
