#include "headers/Deck.hpp"
Deck::Deck(bool size_is_36){
    DBG_CTOR("Deck",this);
    this->deck_.reserve(size_is_36 ? 36 : 52);
    for(uint8_t suit = 0; suit <  4;++suit)
    {
        for(uint8_t value = (size_is_36 ? 4:0); value < 13;++value)
        {
            this->deck_.emplace_back(static_cast<Suit>(suit),static_cast<Value>(value));
        }
    }
    auto rd = std::random_device{};
	auto rng = std::mt19937_64{ rd() };
	std::shuffle(this->deck_.begin(), this->deck_.end(), rng);
    std::uniform_int_distribution<short> dis(0,3);
    this->master_suit_ = static_cast<Suit>(dis(rng));
}
Deck::~Deck()
{
    DBG_DTOR("Deck",this);
}
Suit Deck::get_master_suit(){
    return master_suit_;
}
Card Deck::pop(){
    assert(!this->deck_.empty());
    Card last_elm = this->deck_.back();
    this->deck_.pop_back();
    return last_elm;
}
const Card& Deck::peek()const{
    assert(!this->deck_.empty());
    return this->deck_.back();
}
bool Deck::empty()const{
    return this->deck_.empty();
}