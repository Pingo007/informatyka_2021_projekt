#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>


#define N 5

struct saveStr
{
	int points;
	int level;
};

class Gui
{
private:
	sf::Font font;
	sf::Text text[7];
	int highscore;
	int points;
	int length = 0;

	saveStr buffor[N];
	sf::Text resultsText[N];

	//functions
	void initFont();
	void initText();
	void initGui();

public:
	Gui();

	~Gui();

	//functions
	void updatePoints(int points);
	void updateHighscore(bool easy);
	void guiDraw(sf::RenderTarget& target);
	void pauseDraw(sf::RenderTarget& target);
	void gameOverDraw(sf::RenderTarget& target);
	void drawEsc(sf::RenderTarget& target);
	void read();
	void drawLast(sf::RenderTarget* target);
};

