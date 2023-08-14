#include "headers/GameScreen.hpp"
GameScreen::GameScreen()
:   
    background_
    (
        sf::Vector2f(Screen::WIDTH,Screen::HEIGHT)
    ),
    return_
    (
        sf::Vector2f(50,850),
        sf::Vector2f(150,75),
        sf::Vector2f(80,865),
        30u,
        DRK_COL::Red,
        DRK_COL::Orange,
        DRK_COL::Orange,
        "Back"
    ),
    table_
    (
        2,
        true //will eventually need to read from file for this
    )
{
    DBG_CTOR("GameScreen",this);
    this->background_.setPosition(sf::Vector2f(0,0));
    this->background_.setFillColor(DRK_COL::CasinoGreen);
    this->table_.top_up_hands();
}
GameScreen::~GameScreen()
{
    DBG_DTOR("GameScreen",this);
}
_Screens GameScreen::HandleEvent(const sf::Event& event,const sf::RenderWindow& window)
{
    if(event.type != event.MouseButtonPressed) return _Screens::NOCHANGE;
    if(this->return_.is_pressed(window,sf::Mouse::Left)) return _Screens::MAIN_MENU;
    return _Screens::NOCHANGE;
}
void GameScreen::UpdateScreen(const sf::RenderWindow& window)
{
    this->return_.update(window);
}
void GameScreen::RenderScreen(sf::RenderWindow& window)const
{
    window.draw(this->background_);
    if(this->table_.view_attacking_cards().at(0) != nullptr) this->table_.view_attacking_cards().at(0)->draw(window);
    this->return_.draw(window);
}
