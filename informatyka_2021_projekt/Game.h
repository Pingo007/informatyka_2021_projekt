#pragma once

#include "Menu.h"
#include "DifficultyMenu.h"
#include "Bird.h"
#include "Spikes.h"
#include "Gui.h"
#include <fstream>


class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event e;;
    Menu menu;
    DifficultyMenu diffMenu;
    int help;
    int help2;

    //Resources 

    //Player
    Bird* bird;
    //Spikes
    Spikes* spikes;
    //Gui
    Gui* gui;

    //private functions

    void initWindow();
    void initVariables();
    void initGame();
    void deleteGame();

public:

    //constructor / destructor
    Game();
    virtual ~Game();

    //logic
    bool isMenuOpen;
    bool isDiffMenuOpen;
    bool isGameRunning;
    bool isGamePaused;
    bool isGameOver;
    bool easy;
    bool isEsc;
    bool flag;

    //functions
    void run();

    void save();

    void updateSFMLEvents();

    void renderMenu();
    void renderGame();
    void updateBird();
    void drawGame();

    void update();
    void render();
};


