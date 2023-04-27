#include "Screen.hpp"
#include "Debug.hpp"
#include "Button.hpp"


class MainScreen : public Screen
{
public:
    MainScreen();
    ~MainScreen();
    void HandleEvent(const sf::Event& event,_Screens& screen)override;
    void UpdateScreen(const sf::RenderWindow& window)override;
    void RenderScreen(sf::RenderWindow& window)const override;
private:
    sf::RectangleShape background_;
    Button logo_;
    Button start_;
    Button settings_;
};