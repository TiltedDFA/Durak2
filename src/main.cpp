#include <SFML/Graphics.hpp>
#include "headers/Table.hpp"
#include "headers/ResourceManager.hpp"
#include "headers/Button.hpp"
int main()
{
    Resource_Manager instance1;
    Table instance2(2,true);
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    Button instance{sf::Vector2f(250,400),sf::Vector2f(500,200),sf::Color::White,
    sf::Color::Cyan,sf::Color::Yellow,"This is button"};
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        instance.update(window);

        window.clear();
        instance.draw(window);
        window.display();
    }

    return 0;
}