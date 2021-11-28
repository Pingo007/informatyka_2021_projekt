#include<iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Example", Style::Default);
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