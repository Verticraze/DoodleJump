#include<iostream>
#include<SFML/Graphics.hpp>
#include<time.h>
struct point { int x, y;};

int main()
{
	srand(time(0));
	sf::RenderWindow app(sf::VideoMode(640, 800), "Doodle Jump");
	app.setFramerateLimit(60);

	sf::Texture t1, t2, t3;

	sf::Sprite spritePlayer(t1);
	sf::Sprite spritePlatform(t2);
	sf::Sprite spriteBackground(t3);

	point plat[20];
	int x =100, y=100,h=200;
	float dx=0.0, dy=0.0;

	for (int i=0;i<10;i++)
	{
		plat[i].x = rand() % 640;
		plat[i].y = rand() % 800;
	}

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

		dy += 0.2f;
		y += dy;
		if (y>500) {dy=-10;}

		if (y > h) 
		{
			for (int i=0;i<10;i++)
			{
				y = h;
				plat[i].y -= dy;
				if (plat[i].y > 800) 
				{ 
					plat[i].y = 0; 
					plat[i].x = rand() % 640;
				};
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x < 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && dy > 0) { dy = 0; }
		}

		spritePlayer.setPosition(x, y);

		app.draw(spriteBackground);
		app.draw(spritePlayer);
		for (int i=0;i<10;i++)
		{
			
		}
		app.display();
	}
	return 0;
}