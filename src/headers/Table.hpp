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
    void set_current_players(uint8_t attackPlyrIndex);
    bool is_attacking_cards_empty()const;
    bool check_valid_defending_move(const Card* attacking_card,const Card* defending_card)const;
    bool check_valid_attacking_move(const Card* attacking_card, int target_index)const;
    bool add_attacking_card(int index_in_hand, int target_table_index);
    bool add_defending_card(int index_in_hand, int target_table_index);
    void clear_table();

    const std::array<const Card*,6>& get_attacking_cards()const;
    const std::array<const Card*,6>& get_defending_cards()const;
private:
    //the cards on tables are stored as pointers since there should be
    //no need to duplicate the cards.
    const uint8_t num_players_;
    bool attackers_turn_;
    std::array<const Card*,6> attacking_cards_;
    std::array<const Card*,6> defending_cards_;
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