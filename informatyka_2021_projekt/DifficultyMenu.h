#pragma once
#include "Menu.h"

#define MAX_NUMBER_OF_ITEMS1 2

class DifficultyMenu
{
private:
	//Variables
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS1];
	sf::Color neonBlue = sf::Color(4, 217, 255);

	//Functions
	void initVariables();
	void initFont();
	void initGui(float width, float height);

public:
	DifficultyMenu();
	~DifficultyMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
};

