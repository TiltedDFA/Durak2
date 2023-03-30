#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "ResourceManager.hpp"
#include <string_view>
#include <SFML/Graphics.hpp>
constexpr std::string_view FONT_PATH{"assets/Retron2000.ttf"};

class Button
{
public:
    Button( const sf::Vector2f& position,
            const sf::Vector2f& size,
            const sf::Color& idle,       
            const sf::Color& hover,
            const sf::Color& press,
            const std::string& txt_msg);
    inline bool is_pressed(const sf::RenderWindow& window,const sf::Mouse::Button& button)const;
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window)const;
private:
    sf::RectangleShape button_body_;
    const sf::Color idle_colour_;
    const sf::Color hover_colour_;
    const sf::Color press_colour_;
    sf::Text button_text_;
    const sf::Font& font_;
};
#endif