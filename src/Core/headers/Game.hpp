#ifndef GAME_HPP
#define GAME_HPP

#include "../../UI/headers/MainScreen.hpp"
#include "../../UI/headers/SettingsScreen.hpp"
#include "SFML/Graphics.hpp"
#include "../../GameLogic/headers/Table.hpp"
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