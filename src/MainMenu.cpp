#include "headers/MainMenu.hpp"

Main_Menu::Main_Menu(Game const* instance) :
     Screen(instance),
     background_
     (
          sf::Vector2f(WINDOW_WIDTH,WINDOW_WIDTH)
     ),
     start_game_
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
     ),
     title_
     (
          sf::Vector2f(100.0f,100.0f),
          sf::Vector2f(1200.0f,400.0f),
          sf::Vector2f(320.0f,150.0f),
          250u,
          DRK_COL::Red,
          DRK_COL::Orange,
          DRK_COL::Orange,
          "DURAK"
     )
     {
          DBG_CTOR("menu", this);
          this->background_.setPosition({0,0});
          this->background_.setFillColor(DRK_COL::CasinoGreen);
     }
Main_Menu::~Main_Menu()
{
     DBG_DTOR("Main Menu", this);  
}
void Main_Menu::handle_input(const sf::Event& event)
{

}
void Main_Menu::update(const sf::RenderWindow& window)
{
     this->start_game_.update(window);
     this->settings_.update(window);
     this->title_.update(window);
}
void Main_Menu::draw(sf::RenderWindow& window)
{
     window.draw(this->background_);
     this->start_game_.draw(window);
     this->settings_.draw(window); 
     this->title_.draw(window);
}