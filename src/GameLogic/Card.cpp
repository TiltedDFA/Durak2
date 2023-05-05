#include "headers/Card.hpp"
Card::Card(Suit suit,Value value)noexcept:
    suit_(suit),
    value_(value),
    card_sprite_(nullptr),
    card_text_(nullptr){}
Card::Card(const Card& other)noexcept:
    suit_(other.suit_),
    value_(other.value_),
    card_sprite_(other.card_sprite_),
    card_text_(other.card_text_){}
Card::~Card()
{
    delete this->card_sprite_;
    delete this->card_text_;
}
Card& Card::operator=(const Card& other)noexcept
{
    if(this == &other) return *this;
    this->suit_  = other.suit_;
    this->value_ = other.value_;
    //deep copy
    this->card_sprite_ = new sf::Sprite(*other.card_sprite_);
    this->card_text_ = new sf::Text(*other.card_text_);
    return *this;
}
Card& Card::operator=(Card&& other)noexcept
{
    if(this == &other) return *this;
    this->suit_  = other.suit_;
    this->value_ = other.value_;
    //since we're moving, need to preserve only 1 ptr to obj
    this->card_sprite_ = other.card_sprite_;
    other.card_sprite_ = nullptr;
    this->card_text_ = other.card_text_;
    other.card_text_ = nullptr;
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
    returnValue += "\n of \n";
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
void Card::delete_sprite()
{
    delete this->card_sprite_;
    this->card_sprite_ = nullptr;
    delete this->card_text_;
    this->card_text_ = nullptr;
}
void Card::add_sprite(sf::Sprite* spr)
{
    this->card_sprite_ = spr;
    this->card_text_ = new sf::Text(
        this->to_string(),
        Resource_Manager::get_font(std::string(FONT_PATH)),
        15u
        );
}
void Card::draw(sf::RenderWindow& window)const
{
    window.draw(*this->card_sprite_);
    window.draw(*this->card_text_);
}
void Card::move(const sf::Vector2f& offset)
{
    this->card_sprite_->move(offset);
}
bool Card::contains_mouse(const sf::RenderWindow& window)const
{
    if(this->card_sprite_ == nullptr) return false;
    return this->card_sprite_->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}