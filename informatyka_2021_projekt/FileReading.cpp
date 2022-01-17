#include "FileReading.h"

void FileReading::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR Failed to load font" << "\n";
	}
}


void FileReading::read()
{
	std::ifstream stream = std::ifstream("results.txt", std::ios::binary);
	stream.seekg(0, stream.end);
	length = stream.tellg();
	length = length / sizeof(saveStruct);

	if (length < N)
	{
		stream.seekg(0, stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStruct) * length);
	}
	else
	{
		stream.seekg(sizeof(saveStruct) * (length - N), stream.beg);
		stream.read((char*)this->buffor, sizeof(saveStruct) * N);
		length = N;
	}

	stream.close();
	for (size_t i = 0; i < N; i++)
	{
		this->resultsText[i].setFont(this->font);
		this->resultsText[i].setFillColor(sf::Color::White);
		this->resultsText[i].setPosition(sf::Vector2f(400.f, 200.0f + 100 * i));

	}
	for (size_t i = 0; i < length; i++)
	{
		this->resultsText[i].setString("Points: " + std::to_string(this->buffor[i].points) + " Level: " + ((this->buffor[i].level == 2) ? "Hard" : "Easy"));
	}
}

