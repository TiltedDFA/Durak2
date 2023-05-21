#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "Screen.hpp"
#include "../../GameLogic/headers/Table.hpp"
#include "Button.hpp"
class GameScreen : public Screen
{
public:
    GameScreen();
    ~GameScreen();
    _Screens HandleEvent(const sf::Event& event,const sf::RenderWindow& window)override;
    void UpdateScreen(const sf::RenderWindow& window)override;
    void RenderScreen(sf::RenderWindow& window)const override;

private:
    sf::RectangleShape background_;
    Button return_;
    Table table_;
};

#endif