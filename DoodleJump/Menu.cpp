#include "Menu.h"
#include<SFML/Graphics.hpp>
Menu::Menu()
{
	sf::RenderWindow app(sf::VideoMode(640, 480), "Doodle");
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text MenuText;
	MenuText.setFont(font);
	MenuText.setString("Start\n\nExit");
	MenuText.setCharacterSize(55);
	MenuText.setFillColor(sf::Color::Red);
	while (app.isOpen())
	{
		app.draw(MenuText);
		app.display();
	}
}