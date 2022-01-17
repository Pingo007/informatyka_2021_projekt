#include "Gui.h"

void Gui::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR Failed to load font" << "\n";
	}
}

void Gui::initText()
{
	//Gui
	int highscore = 94;
	int points = 0;
	std::string highscoreS = std::to_string(highscore);
	std::string pointsS = std::to_string(points);

	this->text[0].Bold;
	this->text[0].setFont(font);
	this->text[0].setString("Points: " + pointsS);
	this->text[0].setCharacterSize(40);
	this->text[0].setFillColor(sf::Color::White);
	this->text[0].setPosition(60.f, 60.f);

	this->text[1].Bold;
	this->text[1].setFont(font);
	this->text[1].setString("");
	this->text[1].setCharacterSize(40);
	this->text[1].setFillColor(sf::Color::White);
	this->text[1].setPosition(540.f - text[1].getGlobalBounds().width, 60.f);

	//Pause
	this->text[2].Bold;
	this->text[2].setFont(font);
	this->text[2].setFillColor(sf::Color::White);
	this->text[2].setString("Click mouse1 to jump\nand Avoid the spikes");
	this->text[2].setPosition(sf::Vector2f(600 / 2.0f - text[2].getGlobalBounds().width,
	800 / 2.0f - 1 * text[2].getGlobalBounds().height));
	this->text[2].setCharacterSize(60);

	//GameOver
	this->text[3].Bold;
	this->text[3].setFont(font);
	this->text[3].setFillColor(sf::Color::White);
	this->text[3].setString("Gameover!");
	this->text[3].setPosition(sf::Vector2f(600 / 2.0f - text[3].getGlobalBounds().width + 40,
		800 / 2.0f - 2 * text[3].getGlobalBounds().height - 50));
	this->text[3].setCharacterSize(50);

	this->text[4].Bold;
	this->text[4].setFont(font);
	this->text[4].setFillColor(sf::Color::White);
	this->text[4].setString("Press ESC to continue");
	this->text[4].setPosition(sf::Vector2f(600 / 2.0f - text[4].getGlobalBounds().width + 40,
		800 / 2.0f - 2 * text[4].getGlobalBounds().height + 50));
	this->text[4].setCharacterSize(50);

	//Esc
	this->text[5].Bold;
	this->text[5].setFont(font);
	this->text[5].setFillColor(sf::Color::White);
	this->text[5].setString("Press ENTER to quit");
	this->text[5].setPosition(sf::Vector2f(600 / 2.0f - text[5].getGlobalBounds().width + 40,
		800 / 2.0f - 2 * text[5].getGlobalBounds().height - 50));
	this->text[5].setCharacterSize(50);

	this->text[6].Bold;
	this->text[6].setFont(font);
	this->text[6].setFillColor(sf::Color::White);
	this->text[6].setString("Press ESC to continue");
	this->text[6].setPosition(sf::Vector2f(600 / 2.0f - text[6].getGlobalBounds().width + 40,
		800 / 2.0f - 2 * text[6].getGlobalBounds().height + 50));
	this->text[6].setCharacterSize(50);
}

void Gui::initGui()
{
	this->initFont();
	this->initText();
}

Gui::Gui()
{
	this->initGui();
	std::cout << "Gui created" << "\n";
}

Gui::~Gui()
{

}

void Gui::updatePoints(int points)
{
	this->text[0].setString("Points: " + std::to_string(points));
}

void Gui::updateHighscore(bool easy)
{

}

void Gui::guiDraw(sf::RenderTarget& target)
{
	target.draw(this->text[0]);
	target.draw(this->text[1]);
}

void Gui::pauseDraw(sf::RenderTarget& target)
{
	target.draw(this->text[2]);
}

void Gui::gameOverDraw(sf::RenderTarget& target)
{
	target.draw(this->text[3]);
	target.draw(this->text[4]);
}

void Gui::drawEsc(sf::RenderTarget& target)
{
	target.draw(this->text[5]);
	target.draw(this->text[6]);
}

void Gui::read()
{

	std::ifstream stream = std::ifstream("results.txt", std::ios::binary);
	stream.seekg(0, stream.end);
	length = stream.tellg();
	length = length / sizeof(saveStr);

	if (length < N)
	{
		stream.seekg(0, stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStr) * length);
	}
	else
	{
		stream.seekg(sizeof(saveStr) * (length - N), stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStr) * N);
		length = N;
	}

	stream.close();
	for (size_t i = 0; i < N; i++)
	{
		this->resultsText[i].setFont(this->font);
		this->resultsText[i].setFillColor(sf::Color::White);
		this->resultsText[i].setPosition(sf::Vector2f(200.f, 200.0f + 100 * i));

	}
	for (size_t i = 0; i < length; i++)
	{
		this->resultsText[i].setString("Points: " + std::to_string(this->buffor[i].points) + " Level: " + ((this->buffor[i].level == 2) ? "Hard" : "Easy"));
	}
	std::cout << "read " << "len: " << length << "\n";
}

void Gui::drawLast(sf::RenderTarget* target)
{
	for (size_t i = 0; i < length; i++)
	{
		target->draw(this->resultsText[i]);
	}
}


