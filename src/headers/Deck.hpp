#pragma once
#include "Card.hpp"
#include <vector>
#include <random>
#include <cassert>
class Deck
{
public:
    //deck_size should only ever be 36 or 52
    Deck()=delete;
    Deck(bool size_is_36);
    ~Deck()=default;

    static Suit get_master_suit();
    static void set_master_suit(Suit new_suit);
    
    Card pop();
    Card peek()const;
    bool empty()const;

private:
    inline static Suit master_suit_;
    std::vector<Card> deck_;
};