/**
 * This file contains the definition of the Card class which will be used
 * to represent cards throught the program. It has support for some basic
 * operator overloads and has a toString method which will be used to 
 * display the cards later in the graphics section.
 * This file also definess enumarations for suit and value which are components
 * of the card class.
 * @file Card.hpp
 * @author Malik Tremain (MalikTremain1@gmail.com)
 * @brief Definion of card, suit and value types
 * @version 0.1
 * @date 2023-03-29
 * @copyright Copyright (c) 2023
 */
#ifndef CARD_HPP
#define CARD_HPP

#include <cstdint> //for uint8_t
#include <string> // for the toString method
#include <algorithm> // for the swap overload
/**
 * @enum Suit  
 * @brief Represents the suits that can be stored in card class
 * 
 * The underlying type of this enum class is uint8_t since it will 
 * not need to represent a large range of numbers.
 */
enum class Suit:uint8_t{
    clubs = 0,
    spades,
    hearts,
    diamonds
}; 
/**
 * @enum Value  
 * @brief Represents the values that can be stored in card class
 * 
 * The underlying type of this enum class is uint8_t since it will 
 * not need to represent a large range of numbers.
 */
enum class Value:uint8_t{
    two=0,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};
/**
 * @class Card
 * @brief Simple representation of cards
 *  
 * This class is used to represent cards throughout the program. It includes
 * a few operator overloads and a ToString method.
 */
class Card
{
public:
    /**
     * @brief Construct a new Card object
     * 
     * @param suit The suit of card
     * @param value The value of the card
     */
    Card(Suit suit,Value value)noexcept;
    /**
     * @brief Destroy the Card object
     * It is the default implamentation
     */
    ~Card()=default;
    /**
     * @brief Copy constructor of card objects
     * 
     * @param other The other card
     */
    Card(const Card& other)noexcept;
    /**
     * @brief Move constructor of card objects
     * 
     * @param other The other card
     * 
     * It is the default implamentation
     */
    Card(Card&& other)=default;
    /**
     * @brief Copy assigment operator
     * 
     * @param other The other card
     * @return Card& a reference to the current object
     */
    Card& operator=(const Card& other)noexcept;
    /**
     * @brief Move assigment operator
     * 
     * @param other The other card
     * @return Card& a reference to the current object
     */
    Card& operator=(Card&& other)noexcept;
    /**
     * @brief Returns the suit of card object
     * 
     * @return The suit stored in the object
     */
    [[nodiscard]]Suit get_suit()const noexcept;
    /**
     * @brief Get the value of the object
     * 
     * @return The value stored in the object 
     */
    [[nodiscard]]Value get_value()const noexcept;
    /**
     * @brief returns string representation of object
     * @return std::string 
     * This is to be used in displaying the cards.
     * The returned string will be formatted correctly for how 
     * it is meant to be displayed.
     */
    [[nodiscard]]std::string to_string()const noexcept;
private:
    /**
     * @brief stores the suit.
     * 
     * This uses the Suit enum class to represent a suit value.
     */
    Suit suit_; 
    /**
     * @brief stores the value of the card.
     * 
     * This uses the Value enum class to reprent the value of the card.
     * Values stored will be numeric cards as well as picture cards.
     */
    Value value_; // The value of the current card
};
#endif