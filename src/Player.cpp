#include "headers/Player.hpp"
//used for the find function in return lowest val function
static bool operator==(const Card& c, const Suit& s){
    return c.get_suit() == s;
}
std::size_t Player::get_hand_size()const
{
    return this->cards_.size();
}
bool Player::hand_is_empty()const
{
    return this->cards_.empty();
}
const std::vector<Card>& Player::get_cards()const
{
    return this->cards_;
}
Card* Player::lowest_master_suit_card()const
{
    if(this->cards_.empty()) return nullptr;
    //checks to see if the deck has any cards which are the same suit as the master suit
    if(std::find(this->cards_.begin(),this->cards_.end(),Deck::get_master_suit()) == this->cards_.end())
    {
        return nullptr;
    }
    Card* current_lowest_card{nullptr};
    for(const Card& i : this->cards_)
    {
        if(i.get_suit() == Deck::get_master_suit())
        {
            if(current_lowest_card == nullptr)
            {
                current_lowest_card = const_cast<Card*>(&i);
            }
            else if(i.get_value() < current_lowest_card->get_value())
            {
                current_lowest_card = const_cast<Card*>(&i);
            }
        }
    }
    return current_lowest_card;
}
const Card& Player::get_card(short index)const
{
    return this->cards_.at(index);
}
Card* Player::pop_card(short index)
{
    if(static_cast<std::size_t>(index) >= this->cards_.size()) return nullptr;

    Card* returnVal{new Card(this->cards_.at(index))};
    this->cards_.erase(this->cards_.begin()+index);
    return returnVal;
}
void Player::add_card_to_hand(const Card& card)
{
    assert(this->cards_.size() < 6);
    this->cards_.push_back(card);
}