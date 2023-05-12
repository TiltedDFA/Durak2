#include "headers/SettingsScreen.hpp"

SettingsScreen::SettingsScreen()
: 
    Screen(),
    background_(sf::Vector2f(Screen::WIDTH,Screen::HEIGHT)),
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
    )
{
    DBG_CTOR("Settings Screen", this);
    this->background_.setPosition({0,0});
    this->background_.setFillColor(DRK_COL::CasinoGreen);
}
SettingsScreen::~SettingsScreen()
{
    DBG_DTOR("Settings Screen", this);
}
_Screens SettingsScreen::HandleEvent(const sf::Event& event,const sf::RenderWindow& window)
{
    if(event.type != event.MouseButtonPressed) return _Screens::NOCHANGE;
    if(this->return_.is_pressed(window,sf::Mouse::Left)) return _Screens::MAIN_MENU;
    return _Screens::NOCHANGE;
}
void SettingsScreen::UpdateScreen(const sf::RenderWindow& window)
{
    this->return_.update(window);
}
void SettingsScreen::RenderScreen(sf::RenderWindow& window)const 
{
    window.draw(this->background_);
    this->return_.draw(window);
} 