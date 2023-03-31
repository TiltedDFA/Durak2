#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Button.hpp"
#include <vector>
constexpr unsigned int WINDOW_WIDTH{1500};
constexpr unsigned int WINDOW_HEIGHT{1000};


class Game;//forward declaration

//To be an abstract class
class Screen
{
public:
    Screen(Game const* instance) : game_instance_(instance){}

    virtual ~Screen(){}
    virtual void handle_input(const sf::Event& event)=0;
    virtual void update(const sf::RenderWindow& window)=0;
    virtual void draw(sf::RenderWindow& window)=0;
protected:
    Game const* game_instance_;
};

#endif