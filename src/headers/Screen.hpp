#ifndef SCREEN_HPP
#define SCREEN_HPP
#include "Debug.hpp"
#include "SFML/Graphics.hpp"

enum class _Screens:uint8_t
{
    NULLSCREEN = 0,
    MAIN_MENU,
    SETTINGS_SCREEN,
    GAME_SCREEN
};
class Screen
{
public:
    static constexpr unsigned HEIGHT = 1080;
    static constexpr unsigned WIDTH = 1920;
public:
    Screen(){};
    virtual ~Screen(){};
    virtual void HandleEvent(const sf::Event& event,_Screens& screen)=0;
    virtual void UpdateScreen(const sf::RenderWindow& window)=0;
    virtual void RenderScreen(sf::RenderWindow& window)const=0;
};

#endif