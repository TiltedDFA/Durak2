#include "headers/Card.hpp"
Card::Card(Suit suit,Value value)noexcept:
    suit_(suit),value_(value){}

Card::Card(const Card& other)noexcept:
    suit_(other.suit_),value_(other.value_){}

Card& Card::operator=(const Card& other)noexcept
{
    if(this == &other) return *this;
    this->suit_  = other.suit_;
    this->value_ = other.value_;
    return *this;
}
Card& Card::operator=(Card&& other)noexcept
{
    if(this == &other) return *this;
    this->suit_  = other.suit_;
    this->value_ = other.value_;
    return *this;
}
Suit Card::get_suit()const noexcept
{
    return this->suit_;
}
Value Card::get_value()const noexcept
{
    return this->value_;
}
std::string Card::to_string()const noexcept
{
    std::string returnValue{};
    switch (this->value_)
    {
    case Value::two:
        returnValue += "Two";
        break;
    case Value::three:
        returnValue += "Three";
        break;
    case Value::four:
        returnValue += "Four";
        break;
    case Value::five:
        returnValue += "Five";
        break;
    case Value::six:
        returnValue += "Six";
        break;
    case Value::seven:
        returnValue += "Seven";
        break;
    case Value::eight:
        returnValue += "Eight";
        break;
    case Value::nine:
        returnValue += "Nine";
        break;
    case Value::ten:
        returnValue += "Ten";
        break;
    case Value::jack:
        returnValue += "Jack";
        break;
    case Value::queen:
        returnValue += "Queen";
        break;
    case Value::king:
        returnValue += "King";
        break;
    case Value::ace:
        returnValue += "Ace";
        break;
    }
    returnValue += " of ";
    switch (this->suit_)
    {
    case Suit::clubs:
        returnValue += "Clubs";
        break;
    case Suit::spades:
        returnValue += "Spades";
        break;
    case Suit::hearts:
        returnValue += "Hearts";
        break;
    case Suit::diamonds:
        returnValue += "Diamods";
        break;
    }
    return returnValue;
}