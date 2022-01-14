#include "Spikes.h"

void Spikes::initSpikes()
{
	this->enemy.setPointCount(3);
	this->enemy.setFillColor(sf::Color::White);
	a = 60.f;
	r = a*sqrt(3.f)/3.f;
	h = 1.5 * r;
	this->enemy.setRadius(r);
	this->enemy.setOutlineColor(sf::Color::Black);
	this->enemy.setOutlineThickness(3.f);
	this->enemy.setOrigin(r, r);
	//this->enemy.rotate(180);
	this->enemy.setPosition(-100.f, -100.f);
	srand(time(NULL));


	//init all
	for (int i = 0; i < 31; i++)
	{
		this->enemies.push_back(this->enemy);
	}

	//Down row
	for (int i = 0; i<10; i++) 
	{
			this->enemies[i].setPosition(a/2.f + 60*i, 800.f - 1.f / 3.f * h );
	}
	//Up row
	int j = 0;
	for (int i = 10; i < 20; i++)
	{
		this->enemies[i].rotate(180);
		this->enemies[i].setPosition(a / 2.f + 60 * j,1.f / 3.f * h );
		j++;
	}
	
	//Right
	j = 0;
	int a = rand() % 9 + 20;
	for (int i = 20; i < 31; i++)
	{
		this->enemies[i].rotate(-90);
		this->enemies[i].setPosition(600 + 2.f / 3.f * h, h + a/2 + 60 * j + 30);
		if(i == a || i == a+1 || i == a + 2)
			this->enemies[i].setPosition(-100.f, -100.f);
		j++;
	}
}

Spikes::Spikes()
{
	this->initSpikes();
	std::cout << "Spikes created" << "\n";
}

Spikes::~Spikes()
{

}

bool Spikes::checkCollisions(sf::CircleShape hitbox)
{
	for (int i = 0; i < 31; i++)
	{
		if (this->enemies[i].getGlobalBounds().intersects(hitbox.getGlobalBounds())) {
			std::cout << "Kolizja" << "\n";
			return true;
		}
	}
	return false;
}

void Spikes::updateSpikes(int bounce, bool easy)
{
	int j;
	int x = 0;
	if (bounce == 1)
	{
		std::cout << "Bounce left" << "\n";
		j = 0;
		if (easy) {
			x = rand() % 9 + 20;
		}
		else
		{
			x = rand() % 10 + 20;
		}
		move = 0;
		for (int i = 20; i < 31; i++)
		{
			this->enemies[i].rotate(180);
			this->enemies[i].setPosition(600 + 2.f / 3.f * h, h + a / 2 + 60 * j + 30);
			if (easy)
			{
				if (i == x || i == x + 1 || i == x + 2) {
					this->enemies[i].setPosition(-100.f, -100.f);
				}
			}
			else
			{
				if (i == x || i == x + 1)
					this->enemies[i].setPosition(-100.f, -100.f);
			}
			j++;
		}
	}
	if (bounce == 2)
	{
		std::cout << "Bounce right" << "\n";
		j = 0;
		if (easy) {
			x = rand() % 9 + 20;
		}
		else
		{
			x = rand() % 10 + 20;
		}
		move = 1;
		for (int i = 20; i < 31; i++)
		{
			this->enemies[i].rotate(180);
			this->enemies[i].setPosition(-2.f/3.f * h, h + a / 2 + 60 * j + 30);
			if (easy) 
			{
				if (i == x || i == x + 1 || i == x + 2) {
					this->enemies[i].setPosition(-100.f, -100.f);
				}
			}
			else
			{
				if (i == x || i == x + 1)
					this->enemies[i].setPosition(-100.f, -100.f);
			}
			j++;
		}
	}
	//Move left
	if (move == 0)
		{
		for (int i = 20; i < 31; i++)
		{
			if (enemies[i].getPosition().x >= 600 - 1.f / 3.f * h)
				this->enemies[i].move(-SPIKE_SPEED, 0.f);
		}
	}
	//Move right
	if (move == 1)
	{
		for (int i = 20; i < 31; i++)
		{
			if (enemies[i].getPosition().x <= 1.f / 3.f * h)
				this->enemies[i].move(SPIKE_SPEED, 0.f);
		}
	}
}

void Spikes::drawSpikes(sf::RenderTarget& target)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		target.draw(this->enemies[i]);
	}
}
