#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

#define N 5

struct saveStruct
{
	int points;
	int level;
};

class FileReading
{
private:
	sf::Font font;
	int length = 0;
	saveStruct buffor[N];
	sf::Text resultsText[N];

	//functions
	void initFont();

public:

	void read();
	void drawLast(sf::RenderTarget& target);
};

