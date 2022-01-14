#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <time.h>

#define SPIKE_SPEED 3.f

class Spikes
{
private:
	sf::CircleShape enemy;
	std::vector<sf::CircleShape> enemies;

	float h;
	float a;
	float r;
	int move = 0;

	//functions
	void initSpikes();

public:
	Spikes();

	~Spikes();

	

	//Functions
	bool checkCollisions(sf::CircleShape hitbox);

	void initFirst(bool easy);

	void updateSpikes(int bounce, bool easy);
	void drawSpikes(sf::RenderTarget& target);
};

