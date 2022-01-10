#pragma once

#include "Menu.h"
#include "DifficultyMenu.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event e;
    Menu menu;
    DifficultyMenu diffMenu;

    //private functions

    void initWindow();
    void initVariables();
public:

    //constructor / destructor
    Game();
    virtual ~Game();

    //functions
    void run();

    bool isMenuOpen;
    bool isDiffMenuOpen;
    bool isGameRunning;
    void updateSFMLEvents();
    void renderMenu();
    void renderGame();
    void update();
    void render();
};


