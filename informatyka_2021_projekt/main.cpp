//Celem gry bêdzie jak najd³u¿sze przetrwanie ataków przeciwników jako lataj¹cy statek kosmiczny
//Gra bêdzie siê sk³ada³a z statku którym steruje gracz oraz wrogami pojawi¹j¹cymi siê z ró¿nych stron
//Gracz ma mo¿liwosc poruszaæ siê statkiem na ca³ym ekranie oraz strzelaæ do oko³a siebie
//Poruszanie bêdzie sterowane klawiszami wasd a strzelanie bêdzie sterowane myszk¹ 
//Gra bêdzie sk³ada siê z kilku trybów o ci¹gle rosn¹cej trudnoœci
//Gracz bêdzie mia³ szansê podnieœæ Power upy które pomog¹ mu w jak najd³u¿szym przetrwaniu
//Adam Pachur
//s185615

#include<iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1000, 800), "Example", Style::Default);
	window.setFramerateLimit(60);
	CircleShape circle(100.f);
	circle.setPosition(window.getSize().x / 2 - circle.getRadius(), window.getSize().y / 2 - circle.getRadius());
	circle.setFillColor(Color::Cyan);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//Update
		window.clear();
		window.draw(circle);
		//Draw

		window.display();
	}
	return 0;
}