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
    void clear_table();
private:
    //the cards on tables are stored as pointers since there should be
    //no need to duplicate the cards.
    const uint8_t num_players_;
    bool attackers_turn;
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