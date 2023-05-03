#ifndef GAME_HPP
#define GAME_HPP

#include "../../UI/headers/Screen.hpp"
#include "../../UI/headers/MainScreen.hpp"
#include "./SFML/Graphics.hpp"
#include "Debug.hpp"
#include "ResourceManager.hpp"

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
    sf::RenderWindow window_;
    Resource_Manager RM_instance_;
    Screen* current_screen_;
};



#endif