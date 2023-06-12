/*

#include "Game.h"




class Czcionki {
public:
	
	sf::Font czcionka_win;

	void czcionka_windows() {
		if (!czcionka_win.loadFromFile("fonts_windows\\arial.ttf")) {
			cerr << "Problem z czcionka ";
		}
	}
};


int main(int argc, char *argv[]) {
	//main window
	sf::RenderWindow glowne_okno(VideoMode(1280, 720, 32), "Menu Sace Invaders!");
	
	

	Czcionki czcionka;


	

	czcionka.czcionka_windows();


	//Buttons 
	Button przycisk_start("Zagraj w gre", { 300,80 }, 30, sf::Color::Blue, sf::Color::Black);
	Button przycisk_wyjscie("Wyjscie", { 300,80 }, 30, sf::Color::Blue, sf::Color::Black);




	//przycisk_start.setFont(czcionka.czcionka_win);
	//przycisk_wyjscie.setFont(czcionka.czcionka_win);

	//przycisk_start.setPosition({ 460,100 });
	//przycisk_wyjscie.setPosition({ 460,200 });

	//Textures

	sf::Texture tekstura_glowne_okno;
	tekstura_glowne_okno.loadFromFile("textures/menu_image.jpg");

	sf::Sprite obrazek_glowne_okno;
	obrazek_glowne_okno.setTexture(tekstura_glowne_okno);
	int opcja_menu;

	while (glowne_okno.isOpen()) {
		sf::Event zdarzenie_okno_glowne;
		while (glowne_okno.pollEvent(zdarzenie_okno_glowne)) {
			if (zdarzenie_okno_glowne.type == Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				glowne_okno.close();
			}
			if (zdarzenie_okno_glowne.type == Event::KeyPressed && zdarzenie_okno_glowne.key.code == Keyboard::Up) {
				przycisk_start.setBackColor(sf::Color::Green);
				przycisk_wyjscie.setBackColor(sf::Color::Blue);
				opcja_menu = 1;


			}
			if (zdarzenie_okno_glowne.type == Event::KeyPressed && zdarzenie_okno_glowne.key.code == Keyboard::Enter)
			{
				if (opcja_menu == 1)
				{
					glowne_okno.close();
					//start game
					//init_game();


				}
				else if (opcja_menu == 2)
				{
					glowne_okno.close();
				}
			}
			if (zdarzenie_okno_glowne.type == Event::KeyPressed && zdarzenie_okno_glowne.key.code == Keyboard::Down) {
				przycisk_wyjscie.setBackColor(sf::Color::Red);
				przycisk_start.setBackColor(sf::Color::Blue);
				opcja_menu = 2;
			}

			switch (zdarzenie_okno_glowne.type) {
			case sf::Event::MouseMoved:
				if (przycisk_start.isMouseOver(glowne_okno)) {
					przycisk_start.setBackColor(sf::Color::Green);
				}
				else {

					przycisk_start.setBackColor(sf::Color::Blue);
				}

				if (przycisk_wyjscie.isMouseOver(glowne_okno)) {
					przycisk_wyjscie.setBackColor(sf::Color::Red);
				}
				else {

					przycisk_wyjscie.setBackColor(sf::Color::Blue);
				}

				break;
			case sf::Event::MouseButtonPressed:
				if (przycisk_start.isMouseOver(glowne_okno)) {
					glowne_okno.close();

					//start game
					//init_game();

				}
				else if (przycisk_wyjscie.isMouseOver(glowne_okno)) {
					glowne_okno.close();
				}



			}

		}
		glowne_okno.clear();
		glowne_okno.draw(obrazek_glowne_okno);
		przycisk_start.drawTo(glowne_okno);
		przycisk_wyjscie.drawTo(glowne_okno);
		glowne_okno.display();
	}
	return 0;
}
*/