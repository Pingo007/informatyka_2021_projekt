#include "Bird.h"

void Bird::initTexture()
{
	//Load a texture from file
	if (!this->texture[0].loadFromFile("Textures/bird1.png"))
	{
		std::cout << "ERROR::BIRD::INITTEXTURE::Could not load texture file." << "\n";
	}
	//Load a texture from file
	if (!this->texture[1].loadFromFile("Textures/bird2.png"))
	{
		std::cout << "ERROR::BIRD::INITTEXTURE::Could not load texture file." << "\n";
	}
	//Load a texture from file
	if (!this->texture[2].loadFromFile("Textures/bird3.png"))
	{
		std::cout << "ERROR::BIRD::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->bg.loadFromFile("Textures/bg1.png"))
	{
		std::cout << "ERROR::BIRD::INITTEXTURE::Could not load texture file." << "\n";
	}
}

Bird::Bird()
{
	this->points = 0;

	this->animationIterator = 0;

	this->initTexture();

	this->animationFrames.push_back(texture[1]);
	this->animationFrames.push_back(texture[2]);
	this->animationFrames.push_back(texture[1]);
	this->animationFrames.push_back(texture[0]);

	this->bgS.setTexture(bg);

	this->birdSprite.setTexture(animationFrames.at(animationIterator));

	this->birdSprite.setPosition(width / 4 - birdSprite.getGlobalBounds().width /2 , height / 2 - birdSprite.getGlobalBounds().height / 2);

	this->birdState = BIRD_STATE_STILL;

	sf::Vector2f origin = sf::Vector2f(birdSprite.getGlobalBounds().width / 2, birdSprite.getGlobalBounds().height / 2);

	this->birdSprite.setOrigin(origin);

	this->rotation = 0;

	//HIT BOX
	this->hitbox.setRadius(12.f);
	sf::Vector2f hitboxOrigin = sf::Vector2f(hitbox.getRadius(), hitbox.getRadius());
	this->hitbox.setOrigin(hitboxOrigin);
	this->hitbox.setPosition(birdSprite.getPosition().x , birdSprite.getPosition().y + 5);
}

Bird::~Bird()
{

}

void Bird::Animate()
{
	if (clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / animationFrames.size())
	{
		if (animationIterator < animationFrames.size() - 1)
		{
			animationIterator++;
		}
		else
		{
			animationIterator = 0;
		}

		birdSprite.setTexture(animationFrames.at(animationIterator));

		clock.restart();
	}
}

void Bird::Update()
{
	this->bounce = 0;

	if (birdSprite.getPosition().x <= birdSprite.getGlobalBounds().width / 2)
	{
		bounce = 1;
		this->points++;
		if (speed >= -5.5f)
			this->speed -= 0.05f;
		std::cout << speed << "\n";
		this->speed = -speed;
		birdSprite.setScale(1.f, 1);
	}

	if (birdSprite.getPosition().x + birdSprite.getGlobalBounds().width/2 >= width)
	{
		bounce = 2;
		this->points++;
		if(speed<=5.5f)
			this->speed += 0.05f;
		std::cout << speed << "\n";
		this->speed = -speed;
		birdSprite.setScale(-1.f, 1);
	}

	if (BIRD_STATE_FALLING == birdState) 
	{
		birdSprite.move(speed, GRAVITY);

		//Hitbox
		hitbox.move(speed, GRAVITY);

		if (speed>0)
		{
			rotation += ROTATION_SPEED;
			if (rotation > 25.0f)
			{
				rotation = 25.0f;
			}
		}
		else
		{
			rotation -= ROTATION_SPEED;
			if (rotation < -25.0f)
			{
				rotation = -25.0f;
			}
		}
		birdSprite.setRotation(rotation);
	}
	else if (BIRD_STATE_FLYING == birdState)
	{
		birdSprite.move(speed, -FLYING_SPEED);

		//Hitbox
		hitbox.move(speed, -FLYING_SPEED);

		if (speed > 0)
		{
			rotation -= ROTATION_SPEED;
			if (rotation < -25.0f)
			{
				rotation = -25.0f;
			}
		}
		else
		{
			rotation += ROTATION_SPEED;
			if (rotation > 25.0f)
			{
				rotation = 25.0f;
			}
		}
		birdSprite.setRotation(rotation);
	}

	if (movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
	{
		movementClock.restart();
		birdState = BIRD_STATE_FALLING;
	}
}

void Bird::Tap()
{
	movementClock.restart();
	birdState = BIRD_STATE_FLYING;
}

int Bird::getPoints()
{
	return points;
}

const sf::CircleShape& Bird::getHitbox() const
{
	return this->hitbox;
}

void Bird::Draw(sf::RenderTarget& target)
{
	target.draw(bgS);
	target.draw(birdSprite);
	//target.draw(hitbox);
}

