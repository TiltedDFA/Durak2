#include "headers/Table.hpp"
Table::Table(uint8_t num_players,bool deck_size_36)
    :num_players_(num_players),attackers_turn(true),
    current_attacker_(0),current_defender_(0)
{
    assert(num_players > 1);
    this->attacking_cards_.fill(nullptr);
    this->defending_cards_.fill(nullptr);
    this->players_ = new Player[num_players];
    this->deck_ = new Deck(deck_size_36);
}
Table::~Table()
{
    delete[] this->players_;
    delete this->deck_;
}
void Table::rotate_current_players()
{
    this->current_attacker_ = (this->current_attacker_ + 1) % this->num_players_;
    this->current_defender_ = (this->current_defender_ + 1) % this->num_players_;
}
void Table::clear_table()
{
    
}   