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

    //following functions are going to be kinda the layer that bridges together the card sprices and the inner game logic
private:
    inline static std::array<std::array<sf::RectangleShape,6>,2> init_placement()
    {
        std::array<std::array<sf::RectangleShape,6>,2> rval;
        for(int i = 0; i < 2;++i)
            for(int j = 0; j < 6;++j)
                rval[i][j] = sf::RectangleShape(sf::Vector2f(364,510));
        return rval;
    }
private:
    //might use the rectangle shapes used to record the possible card placement boxes to actually draw where they are
    inline static std::array<std::array<sf::RectangleShape,6>,2> placement_boxes = init_placement();
    sf::RectangleShape background_;
    Button return_;
    Table table_;
};

#endif