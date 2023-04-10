#include "headers/GameScreen.hpp"

GameScreen::GameScreen(Game* instance)
    :Screen(instance),
    background_
    (
        sf::Vector2f(WINDOW_WIDTH,WINDOW_WIDTH)
    )
{
    DBG_CTOR("Game Screen", this);
    this->background_.setPosition({0,0});
    this->background_.setFillColor(DRK_COL::CasinoGreen);
}   
GameScreen::~GameScreen()
{
    DBG_DTOR("Game Screen", this);
}
void GameScreen::handle_input(const sf::Event& event,const sf::RenderWindow& window)
{
     switch (event.type)
     {
     case sf::Event::EventType::MouseButtonReleased:
        break;
     
     default:
        break;
     }
}
void GameScreen::update(const sf::RenderWindow& window)
{
}
void GameScreen::draw(sf::RenderWindow& window)
{
    window.draw(this->background_);
}