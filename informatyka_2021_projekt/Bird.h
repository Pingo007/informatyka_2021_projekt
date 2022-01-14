#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string> 

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 6.f
#define FLYING_SPEED 6.f
#define X_SPEED 3.f

#define FLYING_DURATION 0.15f

#define ROTATION_SPEED 4.f

class Bird
{
private:
	float width = 600;
	float height = 800;
	float speed = X_SPEED;

	int points;

	sf::Sprite birdSprite;
	sf::Texture texture[3];
	sf::Sprite bgS;
	sf::Texture bg;
	sf::CircleShape hitbox;

	std::vector<sf::Texture>  animationFrames;
	unsigned int animationIterator;

	sf::Clock clock;

	sf::Clock movementClock;

	int birdState;

	float rotation;
	//Fuctions
	void initTexture();

public:
	Bird();

	~Bird();

	//Logic
	int bounce;
	
	const sf::CircleShape& getHitbox() const;

	void Draw(sf::RenderTarget& target);

	void Animate();

	void updateText();
	void Update();

	void Tap();

	int getPoints();

};

