#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "DifficultyMenu.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Spaceship invasion", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
    this->isMenuOpen = true;
    this->isDiffMenuOpen = false;
    this->isGameRunning = false;
}

void Game::initPlayer()
{
    this->player = new Player();
}

void Game::initTexture()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initTexture();
    this->initPlayer();
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //Delete textures
    for (auto &i : this->textures)
    {
        delete i.second;
    }
    
    //Delete Bullets
    for (auto *i : this->bullets) 
    {
        delete i;
    }
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->e))
    {
        //this->menuControl();
        switch (this->e.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyReleased:
            switch (e.key.code)
            {
            case sf::Keyboard::Up:
                if (isMenuOpen)
                    menu.MoveUp();
                //diffMenu
                if (menu.GetPressedItem() == 0 && !isMenuOpen && !isGameRunning)
                    diffMenu.MoveUp();
                break;

            case sf::Keyboard::Down:
                if (isMenuOpen)
                    menu.MoveDown();
                //diffMenu
                if (menu.GetPressedItem() == 0 && !isMenuOpen && !isGameRunning)
                    diffMenu.MoveDown();
                break;

            case sf::Keyboard::Escape:
                if (isGameRunning) {
                    isGameRunning = false;
                    isDiffMenuOpen = true;
                }
                else {
                    isDiffMenuOpen = false;
                    isMenuOpen = true;
                    isGameRunning = false;
                }
                break;

            case sf::Keyboard::Return:
                //Glowne Menu klikanie enter
                if (isMenuOpen) {
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Play" << std::endl;
                        isDiffMenuOpen = true;
                        isMenuOpen = false;
                        break;
                    case 1:
                        std::cout << "Help" << std::endl;
                        isMenuOpen = false;
                        break;
                    case 2:
                        this->window->close();
                        break;
                    }
                    break;
                }
                //Diff Menu klikanie enter
                else if (!isGameRunning && !isMenuOpen && menu.GetPressedItem() == 0) {
                    switch (diffMenu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Easy" << std::endl;
                        isDiffMenuOpen = false;
                        isGameRunning = true;
                        break;
                    case 1:
                        std::cout << "Hard" << std::endl;
                        isDiffMenuOpen = false;
                        isGameRunning = true;
                        break;
                    }
                    break;
                }
            }
            break;
        }
    }
}

void Game::updateGame()
{
    if (isGameRunning) {
        // Move player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->player->move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->player->move(1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->player->move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->player->move(0.f, 1.f);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->bullets.push_back(new Bullet(this->textures["BULLET"], 544.f, 347.5f, 0.f, -1.f, 10.f));
        }
    }

}

void Game::updateBulets()
{
    for (auto* bullet : this->bullets) {
        bullet->update();
    }
}


void Game::update()
{
    this->updateSFMLEvents();
    this->updateGame();
    this->updateBulets();
}

void Game::renderMenu()
{
    //Draw Menu
    if (isMenuOpen == true) {
        this->menu.draw(*this->window);
    }
    //Draw play
    else if (menu.GetPressedItem() == 0 && isDiffMenuOpen) {
        this->diffMenu.draw(*this->window);
    }
    //Draw help
    else if (menu.GetPressedItem() == 1) {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Green);
        this->window->draw(shape);
    }
}

void Game::renderGame()
{
    //Easy
    if (isGameRunning && diffMenu.GetPressedItem() == 0) {
        this->player->render(*this->window);

        for (auto* bullet : this->bullets) {
            bullet->render(this->window);
        }
    }

    //Hard
    if (isGameRunning && diffMenu.GetPressedItem() == 1) {
        this->player->render(*this->window);

        for (auto* bullet : this->bullets) {
            bullet->render(this->window);
        }
    }
}

void Game::render()
{
    this->window->clear();
    //rendering
    this->renderMenu();
    this->renderGame();

    this->window->display();
}
