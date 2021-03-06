#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
	//Variables
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Color neonBlue = sf::Color(4, 217, 255);
	
	//Functions
	void initVariables();
	void initFont();
	void initGui(float width, float height);

public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
};