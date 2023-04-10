#ifndef GAME_HPP
#define GAME_HPP

#include "Table.hpp"
#include "MainMenu.hpp"
#include <stack>
#include <SFML/Graphics.hpp>
class Game
{
public:
    Game();
    ~Game();

    void run();
    void add_screen_to_stack(Screen* screen);
    void pop_screen_stack();
private:
    sf::RenderWindow window_;
    Resource_Manager RM_instance;
    std::stack<Screen*> screen_stack_;
};






#endif