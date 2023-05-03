#include "headers/Game.hpp"
Game::Game()
{
    DBG_CTOR("Game", this);
    window_.create(sf::VideoMode(Screen::WIDTH,Screen::HEIGHT), "Durak");
    window_.setFramerateLimit(90);
    current_screen_ = new MainScreen();
}
Game::~Game()
{
    DBG_DTOR("Game", this);
    delete current_screen_;
}
void Game::run()
{
    while (window_.isOpen())
    {
        sf::Event event{};
        while (window_.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window_.close();
        }
        window_.clear();
        current_screen_->UpdateScreen(window_);
        current_screen_->RenderScreen(window_);
        window_.display();
    }
}