#include "Screen.hpp"
#include "Button.hpp"


class MainScreen : public Screen
{
public:
    MainScreen();
    ~MainScreen();
    _Screens HandleEvent(const sf::Event& event)override;
    void UpdateScreen(const sf::RenderWindow& window)override;
    void RenderScreen(sf::RenderWindow& window)const override;
private:
    sf::RectangleShape background_;
    Button logo_;
    Button start_;
    Button settings_;
};