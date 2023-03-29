/**
 * 
 * 
 * @file Table.hpp
 * @author Malik Tremain (MalikTremain1@gmail.com)
 * @brief Definion of the Table class. This will do most of the heavy lifiting for Durak's game logic.
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TABLE_HPP
#define TABLE_HPP
#include "Player.hpp"
class Table
{
public:
    Table()=delete;
    Table(uint8_t num_players,bool deck_size_36);
    ~Table();

    void rotate_current_players();
    bool check_valid_move(Card* attacking_card,Card* defending_card);
    bool add_attacking_card(int index);
    bool add_defending_card(int index);
    void clear_table();
private:
    //the cards on tables are stored as pointers since there should be
    //no need to duplicate the cards.
    const uint8_t num_players_;
    bool attackers_turn;
    std::array<Card*,6> attacking_cards_;
    std::array<Card*,6> defending_cards_;
    //these will hold the indexes of the current 
    //players from the players arrays
    uint8_t current_attacker_;
    uint8_t current_defender_;
    //all variables below will be heap allocated
    //this will be an array with all the players
    Player* players_;
    Deck* deck_;
};
#endif