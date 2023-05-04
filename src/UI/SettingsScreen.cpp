#include "headers/SettingsScreen.hpp"

SettingsScreen::SettingsScreen()
: background_(sf::Vector2f(Screen::WIDTH,Screen::HEIGHT))
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

}
void SettingsScreen::UpdateScreen(const sf::RenderWindow& window)
{

}
void SettingsScreen::RenderScreen(sf::RenderWindow& window)const 
{
    window.draw(this->background_);
} 