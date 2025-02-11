#pragma once
#include<SFML/Graphics.hpp>
#define Menu_items 4
class Menu
{
public:
	Menu(float height,float width);

	void draw(sf::RenderWindow& app);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed() { return MainMenuSelected; };
	~Menu();
private:
		int MainMenuSelected;
		sf::Font font;
		sf::Text mainMenu[Menu_items];
};

