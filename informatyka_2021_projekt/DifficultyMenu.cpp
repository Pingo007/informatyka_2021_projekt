#include "DifficultyMenu.h"

void DifficultyMenu::initVariables()
{
	selectedItemIndex = 0;
}

void DifficultyMenu::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR Failed to load font" << "\n";
	}
}

void DifficultyMenu::initGui(float width, float height)
{
	menu[0].setFont(font);
	menu[0].setFillColor(neonBlue);
	menu[0].setString("Easy");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Hard");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 2));
}

DifficultyMenu::DifficultyMenu()
{
	initVariables();
	initFont();
	initGui(1200, 800);
}

DifficultyMenu::~DifficultyMenu()
{

}

void DifficultyMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS1; i++)
	{
		window.draw(menu[i]);
	}
}

void DifficultyMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(neonBlue);
	}
}

void DifficultyMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(neonBlue);
	}
}

int DifficultyMenu::GetPressedItem()
{
	return selectedItemIndex;
}
