#include "Menu.h"
#include<SFML/Graphics.hpp>
Menu::Menu(float height, float width)
{
	font.loadFromFile("arial.ttf");

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(80);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(80);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(80);

	MainMenuSelected = -1;
	
	sf::RenderWindow app(sf::VideoMode(height, width), "Doodle");
	while (app.isOpen())
	{
	
		app.display();
	}
	
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& app)
{
	for (int i = 0; i < Menu_items; i++)
	{
		app.draw(mainMenu[i]);
	}
}

void Menu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (MainMenuSelected + 1 <= Menu_items)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == Menu_items)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}