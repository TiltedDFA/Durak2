#include "headers/Button.hpp"

Button::Button( const sf::Vector2f& position,
                const sf::Vector2f& size,
                const sf::Color& idle,       
                const sf::Color& hover,
                const sf::Color& press,
                const std::string& txt_msg)
:idle_colour_(idle),hover_colour_(hover),
press_colour_(press),font_(Resource_Manager::get_font(std::string(FONT_PATH)))
{
    this->button_text_.setPosition(sf::Vector2f(position.x + (size.x/3),position.y + (size.y/3)));
    this->button_text_.setOutlineThickness(5.0f);
    this->button_text_.setOutlineColor(sf::Color::Black);
    this->button_text_.setFillColor(this->idle_colour_);
    this->button_text_.setString(txt_msg);
}
inline bool Button::is_pressed(const sf::RenderWindow& window,const sf::Mouse::Button& button)const{
    const bool mouse_colides = this->button_body_.getGlobalBounds().contains(
        sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    return (sf::Mouse::isButtonPressed(button) && mouse_colides);
}
void Button::update(const sf::RenderWindow& window)
{
    const bool mouse_colides = this->button_body_.getGlobalBounds().contains(
        sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    if(!mouse_colides) this->button_body_.setFillColor(this->idle_colour_);return;
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))this->button_body_.setFillColor(this->hover_colour_);return;
    this->button_body_.setFillColor(this->press_colour_);
}
void Button::draw(sf::RenderWindow& window)const
{
    window.draw(this->button_body_);
    window.draw(this->button_text_);
}