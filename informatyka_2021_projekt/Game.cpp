#include <iostream>
#include "Game.h"
#include "Menu.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Asteriods gone wrong!", sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
    this->isMenuOpen = true;
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
    while (this->window->pollEvent(this->sfEvent))
    {
        switch (this->sfEvent.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyReleased:
            switch (sfEvent.key.code)
            {
            case sf::Keyboard::Up:
                if (isMenuOpen)
                    menu.MoveUp();
                break;

            case sf::Keyboard::Down:
                if (isMenuOpen)
                    menu.MoveDown();
                break;

            case sf::Keyboard::Escape:
                isMenuOpen = true;
                break;

            case sf::Keyboard::Return:
                switch (menu.GetPressedItem())
                {
                case 0:
                    if (isMenuOpen)
                        std::cout << "Play button has been pressed" << std::endl;
                    isMenuOpen = false;
                    break;
                case 1:
                    if (isMenuOpen)
                        std::cout << "Option button has been pressed" << std::endl;
                    isMenuOpen = false;
                    break;
                case 2:
                    this->window->close();
                    break;
                }
                break;
            }
            break;
        }
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
    //Draw open menu
    if (isMenuOpen == true) {
        this->menu.draw(*this->window);
    }
    //Draw play
    else if (menu.GetPressedItem() == 0) {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Red);
        this->window->draw(shape);
    }
    //Draw option
    else if (menu.GetPressedItem() == 1) {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Green);
        this->window->draw(shape);
    }

    this->window->display();
}