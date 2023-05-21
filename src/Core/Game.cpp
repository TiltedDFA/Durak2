#include "headers/Game.hpp"
Game::Game()
{
    DBG_CTOR("Game", this);
    this->window_.create(sf::VideoMode(Screen::WIDTH,Screen::HEIGHT), "Durak", sf::Style::Titlebar);
    this->window_.setFramerateLimit(90);
    this->current_screen_ = new MainScreen();
}
Game::~Game()
{
    DBG_DTOR("Game", this);
    delete this->current_screen_;
}
void Game::run()
{
    while (this->window_.isOpen())
    {
        sf::Event event{};
        while (this->window_.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                this->window_.close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    this->window_.close();
                break;
            case sf::Event::Resized:
                break;
            default:
                break;
            }
            switch(this->current_screen_->HandleEvent(event,this->window_))
            {
            case _Screens::NOCHANGE:
                break;
                
            case _Screens::GAME_SCREEN:
                {
                    Screen* temp_ptr{this->current_screen_};
                    this->current_screen_ = new GameScreen();
                    delete temp_ptr;
                }
                break;

            case _Screens::MAIN_MENU:
                {
                    Screen* temp_ptr{this->current_screen_};
                    this->current_screen_ = new MainScreen();
                    delete temp_ptr;
                }
                break;

            case _Screens::SETTINGS_SCREEN:
                {
                    Screen* temp_ptr{this->current_screen_};
                    this->current_screen_ = new SettingsScreen();
                    delete temp_ptr;
                }
                break;
            }
        }
        this->current_screen_->UpdateScreen(window_);
        this->window_.clear();
        this->current_screen_->RenderScreen(window_);
        this->window_.display();
    }
}