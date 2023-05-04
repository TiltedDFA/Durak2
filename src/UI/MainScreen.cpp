#include "headers/MainScreen.hpp"

MainScreen::MainScreen()
    :
    background_
    (
        sf::Vector2f(Screen::WIDTH,Screen::HEIGHT)
    ),
    logo_
    (
        sf::Vector2f(Screen::WIDTH/5,Screen::HEIGHT/12),
        sf::Vector2f(Screen::WIDTH/1.6,Screen::HEIGHT/2.5),
        sf::Vector2f(Screen::WIDTH/3,Screen::HEIGHT/5),
        static_cast<unsigned>((Screen::WIDTH*Screen::HEIGHT)/8200),
        DRK_COL::Red,
        DRK_COL::Orange,
        DRK_COL::Orange,
        "DURAK"
    ),
    start_
    (
        sf::Vector2f(Screen::WIDTH/4,Screen::HEIGHT/1.8),
        sf::Vector2f(Screen::WIDTH/2,Screen::HEIGHT/7.2),
        sf::Vector2f(Screen::WIDTH/2.5,Screen::HEIGHT/1.74),
        static_cast<unsigned>((Screen::WIDTH*Screen::HEIGHT)/15'000),
        DRK_COL::Blue,
        DRK_COL::SkyBlue,
        DRK_COL::SkyBlue,
        "Start"
    ),
    settings_
    (
        sf::Vector2f(Screen::WIDTH/4,Screen::HEIGHT/1.3),
        sf::Vector2f(Screen::WIDTH/2,Screen::HEIGHT/7.2),
        sf::Vector2f(Screen::WIDTH/2.8,Screen::HEIGHT/1.27),
        static_cast<unsigned>((Screen::WIDTH*Screen::HEIGHT)/15'000),
        DRK_COL::Blue,
        DRK_COL::SkyBlue,
        DRK_COL::SkyBlue,
        "Settings"
    )
{
    DBG_CTOR("Main Menu", this);
    this->background_.setPosition({0,0});
    this->background_.setFillColor(DRK_COL::CasinoGreen);
}
MainScreen::~MainScreen()
{
    DBG_DTOR("Main Menu", this);
}
_Screens MainScreen::HandleEvent(const sf::Event& event)
{
    return _Screens::NOCHANGE;
}
void MainScreen::UpdateScreen(const sf::RenderWindow& window)
{
    this->logo_.update(window);
    this->settings_.update(window);
    this->start_.update(window);
}
void MainScreen::RenderScreen(sf::RenderWindow& window)const 
{
    window.draw(this->background_);
    this->logo_.draw(window);
    this->logo_.draw(window);
    this->settings_.draw(window);
    this->start_.draw(window);
} 