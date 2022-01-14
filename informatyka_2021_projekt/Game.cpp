#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "DifficultyMenu.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Spaceship invasion", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
    this->isMenuOpen = true;
    this->isDiffMenuOpen = false;
    this->isGameRunning = false;
    this->isGamePaused = false;
    this->isGameOver = false;
    this->help = 0;
    this->help2 = 0;
    this->isEsc = false;
}

void Game::initGame()
{
    this->bird = new Bird();
    this->spikes = new Spikes();
    this->gui = new Gui();
}

void Game::deleteGame()
{
    delete this->bird;
    delete this->spikes;
    delete this->gui;
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
        switch (this->e.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyReleased:
            switch (e.key.code)
            {
            //Pauzowanie
            case sf::Keyboard::F1:
                if (isGameRunning && !isGameOver &&!isEsc)
                {
                    if (help == 0) {
                        std::cout << "Paused" << "\n";
                        isGamePaused = true;
                        help++;
                    }
                    else {
                        std::cout << "Resumed" << "\n";
                        isGamePaused = false;
                        help = 0;
                    }
                }
                break;
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
                if (isGameRunning && !isGameOver &&!isGamePaused) 
                {
                    if (help2 == 0) {
                        std::cout << "isEsc true" << "\n";
                        isEsc = true;
                        help2++;
                    }
                    else {
                        std::cout << "isEsc false" << "\n";
                        isEsc = false;
                        help2 = 0;
                    }
                }

                if (isGameRunning && isGameOver)
                {
                    std::cout << "kurwa test" << "\n";
                    deleteGame();
                    help = 0;
                    isGameOver = false;
                    isGamePaused = false;
                    isGameRunning = false;
                    isDiffMenuOpen = true;
                }
                else if(!isGameRunning) 
                {
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
                else if (!isGameRunning && !isMenuOpen && menu.GetPressedItem() == 0 &&!isEsc) {
                    switch (diffMenu.GetPressedItem())
                    {
                    case 0:
                        this->initGame();
                        std::cout << "Easy" << std::endl;
                        isDiffMenuOpen = false;
                        isGameRunning = true;
                        easy = true;
                        break;
                    case 1:
                        std::cout << "Hard" << std::endl;
                        this->initGame();
                        isDiffMenuOpen = false;
                        isGameRunning = true;
                        easy = false;
                        break;
                    }
                    break;
                }
                if (isEsc)
                {
                    if (isGameRunning)
                    {
                        std::cout << "kurwa test" << "\n";
                        deleteGame();
                        help = 0;
                        isGameOver = false;
                        isGamePaused = false;
                        isGameRunning = false;
                        isDiffMenuOpen = true;
                        isEsc = false;
                        help2 = 0;
                    }
                }
            }
            break;
        }
    }
}

void Game::updateBird()
{
    if (isGameRunning && !isGamePaused && !isGameOver && !isEsc) {
        //std::cout << bird->getPoints() << "\n";
        this->bird->Animate();
        this->bird->Update();
        this->spikes->updateSpikes(this->bird->bounce, easy);
        this->gui->updatePoints(this->bird->getPoints());
        if (this->spikes->checkCollisions(bird->getHitbox()))
        {
            this->isGameOver = true;
            std::cout << "GameOver" << "\n";
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->bird->Tap();
        }
    }
}

void Game::update()
{
    this->updateSFMLEvents();
    this->updateBird();
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
    if (isGameRunning && diffMenu.GetPressedItem() == 0) 
    {
        this->bird->Draw(*this->window);
        this->spikes->drawSpikes(*this->window);
        this->gui->guiDraw(*this->window);
        if (isGamePaused)
            this->gui->pauseDraw(*this->window);

        if (isGameOver)
            this->gui->gameOverDraw(*this->window);

        if (isEsc)
            this->gui->drawEsc(*this->window);
    }

    //Hard
    if (isGameRunning && diffMenu.GetPressedItem() == 1) 
    {
        this->bird->Draw(*this->window);
        this->spikes->drawSpikes(*this->window);
        this->gui->guiDraw(*this->window);
        if (isGamePaused)
            this->gui->pauseDraw(*this->window);

        if (isGameOver)
            this->gui->gameOverDraw(*this->window);

        if (isEsc)
            this->gui->drawEsc(*this->window);
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
