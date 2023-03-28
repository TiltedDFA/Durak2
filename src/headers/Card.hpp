#ifndef CARD_HPP
#define CARD_HPP
#include <cstdint>
#include <string>
#include <algorithm>
enum class Suit:uint8_t{
    clubs = 0,
    spades,
    hearts,
    diamonds
};
enum class Value:uint8_t{
    two=0,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};
class Card
{
public:
    Card(Suit suit,Value value)noexcept;
    ~Card()=default;
    
    //this overload is needed for the shuffle in deck ctor
    friend void swap(Card& a, Card&b) noexcept{
        Card temp{a};
        a = b;
        b = temp;
    }
    [[nodiscard]]Suit get_suit()const noexcept;
    [[nodiscard]]Value get_value()const noexcept;
    [[nodiscard]]std::string to_string()const noexcept;
private:
    Suit suit_;
    Value value_;
};
#endif