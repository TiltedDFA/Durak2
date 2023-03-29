/**
 * @file Deck.hpp
 * @author Malik Tremain (MalikTremain1@gmail.com)
 * @brief Definion of the Deck class used to store cards
 * @version 0.1
 * @date 2023-03-29
 * This file contains the declarations of the Deck class which 
 * will be used throught the program to store all of the remaining 
 * cards and to deal them randomly when needed. It will also store
 * the master suit which is an important mechanic in the game
 * @copyright Copyright (c) 2023
 */
#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp" //For the card class
#include <vector>   //For the vector data structure
#include <random>   //Used for the random generator. Used for finding the master suit and shuffling the deck.
#include <cassert>  //Used for general debugging throught
/**
 * @class Deck 
 * @brief Stores all of the cards and randomly deals them.
 * 
 * Stores all of the unplayed cards and randomly deals them when needed.
 * The class will also store the master suit suit which is a core game 
 * mechanic.
 */
class Deck
{
public:
    /**
     * @brief Deleted default constructor
     * The deck should never be constructed without a specified size
     */
    Deck()=delete;
    /**
     * @brief Construct a new Deck object 
     * 
     * @param size_is_36 Specifies size of the constructed deck
     * 
     * The size_is_36 parameter is a boolean which will detirmin
     * whether the deck will be 36 or 52 cards.
     * After generating the cards, the order which they are in are 
     * shuffled.
     * This will also set the master suit which is picked randomly.
     */
    Deck(bool size_is_36);
    /**
     * @brief Destroys the Deck object
     * 
     * It is the default version of the destructor
     */
    ~Deck()=default;

    /**
     * @brief Returns the master suit
     * 
     * @return Suit enum class type 
     */
    static Suit get_master_suit();
    
    /**
     * @brief Removes the last card in the deck.
     * 
     * @return Temporary object with the value of the removed card.
     * 
     * This also asserts that the deck is not empty.
     */
    Card pop();
    /**
     * @brief Returns the value of the last card in the deck.
     * 
     * @return A constant reference to the last element in the deck.
     * 
     * This also asserts that the deck is not empty.
     */
    [[nodiscard]]const Card& peek()const;
    /**
     * @brief Checks whether the deck is empty.
     * 
     * @return A boolean representing whether the deck is empty.
     */
    [[nodiscard]]bool empty()const;

private:
    inline static Suit master_suit_;//The master Suit. Static since there should only be one master suit per game
    std::vector<Card> deck_; //All of the remaining cards which have not been played yet.
};
#endif