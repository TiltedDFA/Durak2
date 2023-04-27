#include "headers/MainScreen.hpp"

MainScreen::MainScreen()
    :
    background_
    (
        sf::Vector2f(Screen::WIDTH,Screen::HEIGHT)
    ),
    logo_
    (
        sf::Vector2f(150.0f,100.0f),
        sf::Vector2f(1200.0f,400.0f),
        sf::Vector2f(320.0f,150.0f),
        250u,
        DRK_COL::Red,
        DRK_COL::Orange,
        DRK_COL::Orange,
        "DURAK"
    ),
    start_
    (
        sf::Vector2f(500.0f,550.0f),
        sf::Vector2f(500.0f,150.0f),
        sf::Vector2f(645.0f,580.0f),
        70u,
        DRK_COL::Blue,
        DRK_COL::SkyBlue,
        DRK_COL::SkyBlue,
        "Start"
    ),
    settings_
    (
        sf::Vector2f(500.0f,750.0f),
        sf::Vector2f(500.0f,150.0f),
        sf::Vector2f(600.0f,775.0f),
        70u,
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
void MainScreen::HandleEvent(const sf::Event& event,_Screens& screen)
{

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