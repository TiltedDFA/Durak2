#include "headers/Game.hpp"
Game::Game()
{
    DBG_CTOR("Game", this);
    this->window_.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Durak");
    this->window_.setFramerateLimit(60);
    this->screen_stack_.push(new Main_Menu(this));
}
Game::~Game()
{
    DBG_DTOR("Game",this);
    while(!this->screen_stack_.empty())
    {
        pop_screen_stack();
    }
}
void Game::add_screen_to_stack(Screen* screen)
{
    this->screen_stack_.push(screen);
}
void Game::pop_screen_stack()
{
    delete this->screen_stack_.top();
    this->screen_stack_.pop();
    if(this->window_.isOpen()) this->window_.close();
}
void Game::run()
{
    while (!this->screen_stack_.empty())
    {
            sf::Event event;
            while (this->window_.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    return;
                if(event.type == sf::Event::Resized)
                {
                    // Get the new size of the window

                    // Set the new size of the view

                // window.setView(sf::View({0,0,static_cast<float>(event.size.width),static_cast<float>(event.size.height)}));
                }
            }
            this->screen_stack_.top()->handle_input(event,this->window_);
            this->screen_stack_.top()->update(this->window_);
            this->window_.clear();
            this->screen_stack_.top()->draw(this->window_);
            this->window_.display();
    }
    this->window_.close();
}   