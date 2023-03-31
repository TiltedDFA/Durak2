#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Screen.hpp"

class Main_Menu : public Screen
{
public:
    Main_Menu(Game const* instance);
    ~Main_Menu()override;
    void handle_input(const sf::Event& event)override;
    void update(const sf::RenderWindow& window)override;
    void draw(sf::RenderWindow& window)override;
private:
    sf::RectangleShape background_;
    Button start_game_;
    Button settings_;
    Button title_;
};



#endif