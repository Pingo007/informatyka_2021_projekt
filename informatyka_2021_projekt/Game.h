#pragma once

#include "Menu.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Menu menu{ 1200.0f,800.0f };

    //private functions

    void initWindow();
    void initVariables();
public:

    //konstruktor/destruktor
    Game();
    virtual ~Game();

    //functions
    void run();

    bool isMenuOpen;
    void updateSFMLEvents();
    void update();
    void render();
};


