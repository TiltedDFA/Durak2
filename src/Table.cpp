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
    for(int i = 0; i < 6;++i)
    {
        delete this->attacking_cards_.at(i);
        delete this->defending_cards_.at(i);
    }
}
void Table::rotate_current_players()
{
    this->current_attacker_ = (this->current_attacker_ + 1) % this->num_players_;
    this->current_defender_ = (this->current_defender_ + 1) % this->num_players_;
}
bool check_valid_move(Card* attacking_card,Card* defending_card)
{

}
bool Table::add_attacking_card(int index)
{
    assert(index > -1 && index < 7);
    const auto card = this->players_[this->current_attacker_].pop_card(index);
    if(card == nullptr) return false;
    this->attacking_cards_[index] = card;
    return true;
}
bool Table::add_defending_card(int index)
{
    assert(index > -1 && index < 7);
    const auto card = this->players_[this->current_defender_].pop_card(index);
    if(card == nullptr) return false;
    this->defending_cards_[index] = card;
    return true;
}
void Table::clear_table()
{
    for(auto& i : attacking_cards_)
    {
        delete i;
        i = nullptr;
    }
    for(auto& i : defending_cards_)
    {
        delete i;
        i = nullptr;
    }
}   