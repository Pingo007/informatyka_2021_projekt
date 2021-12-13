//Celem gry b�dzie jak najd�u�sze przetrwanie atak�w przeciwnik�w jako lataj�cy statek kosmiczny
//Gra b�dzie si� sk�ada�a z statku kt�rym steruje gracz oraz wrogami pojawi�j�cymi si� z r�nych stron
//Gracz ma mo�liwosc porusza� si� statkiem na ca�ym ekranie oraz strzela� do oko�a siebie
//Poruszanie b�dzie sterowane klawiszami wasd a strzelanie b�dzie sterowane myszk� 
//Gra b�dzie sk�ada si� z kilku tryb�w o ci�gle rosn�cej trudno�ci
//Gracz b�dzie mia� szans� podnie�� Power upy kt�re pomog� mu w jak najd�u�szym przetrwaniu
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