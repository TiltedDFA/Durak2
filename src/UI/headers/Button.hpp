/**
 * @file Button.hpp
 * @author Malik Tremain (MalikTremain1@gmail.com)
 * @brief This is a file which defines a button used for gui
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 * This file defines a general purpose button with some methods for general use.
 * This should make designing screens much easier and reduce clutter
 */
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../../Core/headers/Debug.hpp"
#include "../../Core/headers/ResourceManager.hpp"
#include <string_view>
#include <SFML/Graphics.hpp>

namespace DRK_COL
{
    static sf::Color Grey(130, 130, 130, 255);
    static sf::Color LightGrey(200, 200, 200, 255);
    static sf::Color Blue(0,121,241,255);
    static sf::Color Red(230,41,55,255);
    static sf::Color Orange(255,203,0,255);
    static sf::Color SkyBlue(102,191,255,255);
    static sf::Color CasinoGreen(42, 107, 18,255);
}
/**
 * @brief This describes the path from the .exe to the font
 * 
 */
constexpr std::string_view FONT_PATH{"../assets/Retron2000.ttf"};
/**
 * @class Button
 * @brief General purpose button for gui
 */
class Button
{
public:
    /**
     * @brief Construct a new Button object.
     * 
     * @param position  The position where you want the button to be (cord of top left corner).
     * @param size      The size of the button.
     * @param txt_pos   The positon that you would like to place the text in
     * @param char_size This is the size of the character in the text
     * @param idle      This is the colour you want the button to show when it's inactive.
     * @param hover     This is the colour you want the button to show when it's hovered over with the mouse.  
     * @param press     This is the colour you want the button to show when it's pressed.
     * @param txt_msg   This is the text that you want displayed on the button.
     * 
     * The constructor makes a lot of assumptions with how you want the button to be designed.
     * It assumes outline colour & thickness. It also assumes the font, size of text and position of text
     * of the button. If the default assumptions are inaccurate, you should change them with the other functions.
     */
    Button( const sf::Vector2f& position,
            const sf::Vector2f& size,
            const sf::Vector2f& txt_pos,
            const unsigned int  char_size,
            const sf::Color&    idle,       
            const sf::Color&    hover,
            const sf::Color&    press,
            const std::string&  txt_msg);
    /**
     * @brief Destroy the Button object.
     * This d-tor is mainly used for debugging purposes with tracking object life time.
     */
    ~Button();
    /**
     * @brief checks whether the button is pressed with the inputted mouse button.
     * 
     * @param window The current window.
     * @param button The mouse button that you want to check.
     * @return true if the mouse is hovering over the button and the input mouseb utton is pressed.
     * @return false if the true conditon is not met.
     */
    bool is_pressed(const sf::RenderWindow& window,const sf::Mouse::Button& button)const;
    /**
     * @brief used to update the button.
     * Used to update the button colour based on it's state detirmined by the mouse.
     * @param window The current window.
     */
    void update(const sf::RenderWindow& window);
    /**
     * @brief draws the button and the text.
     * 
     * @param window The current window.
     */
    void draw(sf::RenderWindow& window)const;
private:
    /**
     * @brief This is an SFML shape which handles most of the data.
     * Used to store things like current colour, position, size and used for
     * mouse overlap checks.
     */
    sf::RectangleShape button_body_;
    /**
     * @brief The colour the button should be when inactive.
     * 
     */
    const sf::Color idle_colour_;
    /**
     * @brief The colour the button should be when hovered over.
     * 
     */
    const sf::Color hover_colour_;
    /**
     * @brief The colour the button should be when pressed.
     * The button will only switch to this colour if the button pressed is the left
     * mouse button.
     * 
     */
    const sf::Color press_colour_;
    /**
     * @brief The text that the button will encapuslate.
     * This is another SFML class which does a lot of the heavy lifing.
     * It stores size,position, font size,colour,outline colour, outline thickness etc.
     */
    sf::Text button_text_;
};
#endif