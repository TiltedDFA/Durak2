#include <SFML/Graphics.hpp>
#include "headers/Table.hpp"
#include "headers/ResourceManager.hpp"
#include "headers/Button.hpp"
int main()
{
    Resource_Manager instance1;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    Button instance{sf::Vector2f(0,0),sf::Vector2f(100,100),sf::Color::White,
    sf::Color::Black,sf::Color::Blue,"This is button"};
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}