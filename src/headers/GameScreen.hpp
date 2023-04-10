#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "Screen.hpp"

class GameScreen : public Screen
{
public:
    GameScreen(Game* instance);
    ~GameScreen()override;
    void handle_input(const sf::Event& event,const sf::RenderWindow& window)override;
    void update(const sf::RenderWindow& window)override;
    void draw(sf::RenderWindow& window)override;
private:
    sf::RectangleShape background_;
};
#endif