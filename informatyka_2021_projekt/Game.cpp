#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "DifficultyMenu.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Spaceship invasion", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
    this->isMenuOpen = true;
    this->isDiffMenuOpen = false;
    this->isGameRunning = false;
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
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
                        std::cout << "Play button has been pressed" << std::endl;
                        isDiffMenuOpen = true;
                        isMenuOpen = false;
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
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
    //Draw option
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
        std::cout << "Easy" << "\n";
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Red);
        this->window->draw(shape);
    }

    //Hard
    if (isGameRunning && diffMenu.GetPressedItem() == 1) {
        std::cout << "Hard" << "\n";
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Yellow);
        this->window->draw(shape);
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}


void Game::render()
{
    this->window->clear();
    //rendering
    this->renderMenu();
    this->renderGame();

    this->window->display();
}
