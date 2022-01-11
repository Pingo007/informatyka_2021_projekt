#pragma once

#include "Menu.h"
#include "DifficultyMenu.h"
#include "Player.h"
#include "Bullet.h"
#include<map>

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event e;
    Menu menu;
    DifficultyMenu diffMenu;

    //Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //Player
    Player* player;

    //private functions

    void initWindow();
    void initTexture();
    void initVariables();
    void initPlayer();

public:

    //constructor / destructor
    Game();
    virtual ~Game();

    //logic
    bool isMenuOpen;
    bool isDiffMenuOpen;
    bool isGameRunning;

    //functions
    void run();

    void updateSFMLEvents();

    void renderMenu();
    void renderGame();
    void updateGame();
    void updateBulets();

    void update();
    void render();
};


