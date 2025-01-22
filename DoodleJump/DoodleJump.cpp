#include<iostream>
#include<SFML/Graphics.hpp>
#include<time.h>
struct point { int x, y;};

int main()
{
	srand(time(0));
	sf::RenderWindow app(sf::VideoMode(640, 360), "Doodle Jump");

	sf::Texture t1, t2, t3;

	sf::Sprite spritePlayer(t1);
	sf::Sprite spritePlatform(t2);
	sf::Sprite spriteBackground(t3);

	point plat[20];
	int x, y;
	while (app.isOpen())
	{
		sf::Event e;

		while(app.pollEvent(e))
		{
			if (e.type = sf::Event::Closed)
			{
				app.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { x += 3; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {x-=3 ; }

		app.draw(spriteBackground);
		app.draw(spritePlayer);
		for (int i=0;i<10;i++)
		{
			
		}
		app.display();
	}
	return 0;
}