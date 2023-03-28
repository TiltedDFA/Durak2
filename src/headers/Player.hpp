#pragma once
#include "Deck.hpp"
#include <array>

class Player
{
public:
    Player()=default;
    ~Player()=default;

    [[nodiscard]]std::size_t get_hand_size()const;
    [[nodiscard]]bool hand_is_empty()const;
    [[nodiscard]]const std::vector<Card>& get_cards()const; 
    [[nodiscard]]Card* lowest_master_suit_card()const;
    void add_card_to_hand(Card card);
private:
    std::vector<Card> cards_;
};
