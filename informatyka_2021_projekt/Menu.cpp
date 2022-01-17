#include "Menu.h"

void Menu::initVariables()
{
	selectedItemIndex = 0;
}

void Menu::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR Failed to load font" << "\n";
	}
}

void Menu::initGui(float width, float height)
{
	menu[0].setFont(font);
	menu[0].setFillColor(neonBlue);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Last Scores");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

Menu::Menu()
{
	initVariables();
	initFont();
	initGui(600,800);
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(neonBlue);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(neonBlue);
	}
}

int Menu::GetPressedItem()
{
	return selectedItemIndex;
}
