/**
 * @file Player.hpp
 * @author Malik Tremain (MalikTremain1@gmail.com)
 * @brief Definion of Player class which is used to store the cards and represent players.
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Deck.hpp"

#include <array>
/**
 * @class Player
 *
 * @brief Stores the player's cards.
 *
 * This class is responsible for storing all of the cards
 * that the player currently has. It has a lot function that
 * are implamented specifically for a use elsewhere.
 */
class Player
{
public:
    /**
     * @brief Construct a new Player object.
     *
     * It is defaulted.
     */
    Player() = default;
    /**
     * @brief Destroys the Player object
     *
     * It is defaulted.
     */
    ~Player() = default;
    /**
     * @brief Returns number of cards currently in player's hand.
     *
     * @return std::size_t : The number of cards currently in the hand.
     *
     * Marked nodiscard since the function should only be called when the return value
     * is needed.
     */
    [[nodiscard]] std::size_t get_hand_size() const;
    /**
     * @brief Checks if the players hand is empty
     *
     * @return bool : T/F depending on whether the hand is currently empty.
     *
     * Marked nodiscard since the function should only be called when the return value
     * is needed.
     */
    [[nodiscard]] bool hand_is_empty() const;
    /**
     * @brief returns all of the cards currently stored.
     *
     * @return const std::vector<Card>& : Return a constant reference to the cards in the hand.
     *
     * Marked nodiscard since the function should only be called when the return value
     * is needed.
     *
     * This is needed for when the current cards need to be used to update the graphics
     */
    [[nodiscard]] const std::vector<Card> &get_cards() const;
    /**
     * @brief finds the lowest value card of the same suit as the master suit.
     *
     * @return Card* : A pointer to the card matching the conditions. Returns nullptr if conditions not met.
     *
     * Marked nodiscard since the function should only be called when the return value
     * is needed.
     *
     * This function will search through all of the cards currently in the player's hand if the
     * hand is not empty. It will then check if there's a card within the hand that is actually
     * of the same suit as the current master suit. Will return a nullptr if either of these prior
     * conditions are true. Else it will iterate through all of the cards and return the a pointer
     * to the current card in the player's hand where the lowest value was found.
     */
    [[nodiscard]] Card *lowest_master_suit_card() const;
    /**
     * @brief returns the card at the specified index.
     *
     * @param index - the index of the data you want.
     * @throw std::out_of_range - thrown by the vector's .at() function if the index is out of bounds
     * @return const Card& returns a reference to the card at the requested index
     */
    [[nodiscard]] const Card &get_card(short index) const;
    /**
     * @brief removes and returns the card at the specified index.
     * 
     * @param index - the index of the data you want.
     * @return Card* - returns a __*NEW*__ card which holds the same data as the deleted card from index.
     * 
     * This function will check if the index is out of bounds. If it is it will then return a nullptr and 
     * it will not change the data inside the hand. If the index it within the allowed range, this function 
     * will then heap allocate a copy of the data in the specified index and return a raw pointer to that new
     * memory. There is no management of lifetime for this new memory and it will need to be explcitly deleted elsewhere.
     */
    [[nodiscard]] Card *pop_card(short index);
    /**
     * @brief adds a card to the back of the vector.
     * 
     * @param card the data you want to add to hand.
     */
    void add_card_to_hand(const Card& card);

private:
    std::vector<Card> cards_;
};
#endif