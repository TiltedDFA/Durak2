#include "headers/Table.hpp"
Table::Table(uint8_t num_players,bool deck_size_36)
    :num_players_(num_players),attackers_turn_(true),
    current_attacker_(0),current_defender_(0)
{
    assert(num_players > 1);
    this->attacking_cards_.fill(nullptr);
    this->defending_cards_.fill(nullptr);
    this->players_ = new Player[num_players]();
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
void Table::set_current_players(uint8_t attackPlyrIndex)
{
    assert(attackPlyrIndex + 1 < this->num_players_ );
    this->current_attacker_ = attackPlyrIndex;
    this->current_defender_ = attackPlyrIndex + 1;
}
void Table::rotate_current_players()
{
    this->current_attacker_ = (this->current_attacker_ + 1) % this->num_players_;
    this->current_defender_ = (this->current_defender_ + 1) % this->num_players_;
}
bool Table::is_attacking_cards_empty()const
{
    for(const auto i : this->attacking_cards_)
    {
        if(i != nullptr) return false;
    }
    return true;
}
bool Table::check_valid_defending_move(const Card* attacking_card,const Card* defending_card)const
{
    const Suit master_suit = Deck::get_master_suit();
    if(attacking_card == nullptr) return false;
    if(attacking_card->get_suit() == master_suit && defending_card->get_suit() != master_suit)
        return false;
    if(attacking_card->get_suit() != master_suit && defending_card->get_suit() == master_suit)
        return true;
    if(attacking_card->get_suit() == defending_card->get_suit() && attacking_card->get_value() < defending_card->get_value())
        return true;
    return false;
}
inline bool Table::check_valid_attacking_move(const Card* attacking_card, int target_index)const
{
    assert(target_index > -1 && target_index < 7);
    if(is_attacking_cards_empty()) return true;
    if(this->attacking_cards_[target_index] != nullptr) return false;
    for(const auto i : this->attacking_cards_)
    {
        if(i != nullptr)
        {
           return (attacking_card->get_value() == this->attacking_cards_[target_index]->get_value());
        }
    }
    return (this->attacking_cards_[target_index] == nullptr);
}
bool Table::add_attacking_card(int index_in_hand, int target_table_index)
{
    assert(index_in_hand > -1 && index_in_hand < 7);
    if(!check_valid_attacking_move(this->players_[this->current_attacker_].get_card(index_in_hand) ,target_table_index))return false;
    const auto card = this->players_[this->current_attacker_].pop_card(index_in_hand);
    if(card == nullptr) return false;
    this->attacking_cards_[target_table_index] = card;
    return true;
}
bool Table::add_defending_card(int index_in_hand, int target_table_index)
{
    assert(target_table_index > -1 && target_table_index < 7);
    if(!check_valid_defending_move(this->attacking_cards_[target_table_index],
    this->players_[this->current_defender_].get_card(index_in_hand)))
    {
        return false;
    }
    const auto card = this->players_[this->current_defender_].pop_card(index_in_hand);
    if(card == nullptr) return false;
    this->defending_cards_[index_in_hand] = card;
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
const std::array<const Card*,6>& Table::get_attacking_cards()const
{
    return this->attacking_cards_;
}
const std::array<const Card*,6>& Table::get_defending_cards()const
{
    return this->defending_cards_;
}