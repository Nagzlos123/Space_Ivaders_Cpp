#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Button{
		public:
				Button(string napis,sf::Vector2f size,int charSize,sf::Color bgColor,sf::Color kolor_napisu){
					tekst.setString(napis);
					tekst.setFillColor(kolor_napisu);
					
					szerokosc_przycisku = size.x;
					wysokosc_przycisku = size.y;

					tekst.setCharacterSize(charSize);
					przycisk.setSize(size);
					przycisk.setFillColor(bgColor);
				}

				void setFont(sf::Font &font){
					tekst.setFont(font);
				}

				void setBackColor(sf::Color color){
					przycisk.setFillColor(color);
				}
				void setTextColor(sf::Color color){
						tekst.setFillColor(color);
				}

				void setPosition(sf::Vector2f pos){
						przycisk.setPosition(pos);
						
						float xPos = (pos.x+przycisk.getGlobalBounds().width/2) - (tekst.getGlobalBounds().width/2);
						float yPos = (pos.y+przycisk.getGlobalBounds().height/2) - (tekst.getGlobalBounds().height/2);
						tekst.setPosition({xPos,yPos});
				} 
				void drawTo(sf::RenderWindow &window){
						window.draw(przycisk);
						window.draw(tekst);
				}
				bool isMouseOver(sf::RenderWindow &window){
						int mouseX = sf::Mouse::getPosition(window).x;
						int mouseY = sf::Mouse::getPosition(window).y;

						float btnPosX = przycisk.getPosition().x;
						float btnPosY = przycisk.getPosition().y;

						float btnxPosWidth = przycisk.getPosition().x + przycisk.getLocalBounds().width;	
						float btnxPosHeight = przycisk.getPosition().y + przycisk.getLocalBounds().height;
						if(mouseX < btnxPosWidth && mouseX  > btnPosX  && mouseY  < btnxPosHeight && mouseY > btnPosY ){
								return true;
						}
						return false;
				}
		private:
				sf::RectangleShape przycisk;
				sf::Text tekst;
				int szerokosc_przycisku;
				int wysokosc_przycisku;


};
