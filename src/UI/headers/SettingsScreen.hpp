#ifndef SETTINGSSCREEN_HPP
#define SETTINGSSCREEN_HPP

#include "Screen.hpp"
#include "Button.hpp"
//need to rethink the file writing system
class SettingsScreen : public Screen
{
public:
    SettingsScreen();
    ~SettingsScreen();
    _Screens HandleEvent(const sf::Event& event,const sf::RenderWindow& window)override;
    void UpdateScreen(const sf::RenderWindow& window)override;
    void RenderScreen(sf::RenderWindow& window)const override;
private:
    sf::RectangleShape background_;
};





#endif