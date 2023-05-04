#ifndef SCREEN_HPP
#define SCREEN_HPP
#include "../../Core/headers/Debug.hpp"
#include "./SFML/Graphics.hpp"

enum class _Screens:uint8_t
{
    NOCHANGE = 0,
    MAIN_MENU,
    SETTINGS_SCREEN,
    GAME_SCREEN
};
class Screen
{
public:
    static constexpr unsigned WIDTH = 1000;
    static constexpr unsigned HEIGHT = 1000;
public:
    Screen(){};
    virtual ~Screen(){};
    virtual _Screens HandleEvent(const sf::Event& event,const sf::RenderWindow& window)=0;
    virtual void UpdateScreen(const sf::RenderWindow& window)=0;
    virtual void RenderScreen(sf::RenderWindow& window)const=0;
};

#endif