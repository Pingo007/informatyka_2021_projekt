#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Gui
{
private:
	sf::Font font;
	sf::Text text[7];
	int highscore;
	int points;
	
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
};

