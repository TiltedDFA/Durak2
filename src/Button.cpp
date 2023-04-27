#include "headers/Button.hpp"

Button::Button( const sf::Vector2f& position,
                const sf::Vector2f& size,
                const sf::Vector2f& txt_pos,
                const unsigned int  char_size,
                const sf::Color& idle,       
                const sf::Color& hover,
                const sf::Color& press,
                const std::string& txt_msg)
    :idle_colour_(idle),hover_colour_(hover),
    press_colour_(press)
{
    DBG_CTOR("Button",this);
    this->button_body_.setSize(size);
    this->button_body_.setPosition(position);
    this->button_body_.setOutlineThickness(5.0f);
    this->button_body_.setFillColor(hover);
    this->button_body_.setOutlineColor(sf::Color::Black);
    this->button_text_.setFont(Resource_Manager::get_font(std::string(FONT_PATH)));
    this->button_text_.setPosition(txt_pos);
    this->button_text_.setOutlineThickness(2.0f);
    this->button_text_.setCharacterSize(char_size);
    this->button_text_.setOutlineColor(sf::Color::Black);
    this->button_text_.setFillColor(this->idle_colour_);
    this->button_text_.setString(txt_msg);
}
Button::~Button()
{
    DBG_DTOR("Button",this);
}
bool Button::is_pressed(const sf::RenderWindow& window,const sf::Mouse::Button& button)const
{
    const bool mouse_colides = this->button_body_.getGlobalBounds().contains(
        sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    return (sf::Mouse::isButtonPressed(button) && mouse_colides);
}
void Button::update(const sf::RenderWindow& window)
{
    const bool mouse_colides = this->button_body_.getGlobalBounds().contains(
        sf::Vector2f(sf::Mouse::getPosition(window)));

    if(!mouse_colides) 
    {
        this->button_body_.setFillColor(this->idle_colour_);
        this->button_text_.setFillColor(this->hover_colour_);
        return;
    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->button_body_.setFillColor(this->hover_colour_);
        this->button_text_.setFillColor(this->idle_colour_);
        return;
    }
    this->button_body_.setFillColor(this->press_colour_);
    this->button_text_.setFillColor(this->idle_colour_);
}

void Button::draw(sf::RenderWindow& window)const
{
    window.draw(this->button_body_);
    window.draw(this->button_text_);
}