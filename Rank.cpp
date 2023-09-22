//
// Created by Dave R. Smith on 2/14/23.
//

#include "Rank.h"

Rank::Rank(){}

Rank::Rank(Ranks rank)
{

    switch (rank)
    {
        case ACE:
            s = "A";
            value = 1;
            break;
        case TWO:
            s = "2";
            value = 2;
            break;
        case THREE:
            s = "3";
            value = 3;
            break;
        case FOUR:
            s = "4";
            value = 4;
            break;
        case FIVE:
            s = "5";
            value = 5;
            break;
        case SIX:
            s = "6";
            value = 6;
            break;
        case SEVEN:
            s = "7";
            value = 7;
            break;
        case EIGHT:
            s = "8";
            value = 8;
            break;
        case NINE:
            s = "9";
            value = 9;
            break;
        case TEN:
            s = "10";
            value = 10;
            break;
        case JACK:
            s = "J";
            value = 10;
            break;
        case QUEEN:
            s = "Q";
            value = 10;
            break;
        case KING:
            s = "K";
            value = 10;
            break;

    }

    top.setFont(Font::getFont());
    top.setCharacterSize(30);
    top.setString(s);

    bottom.setFont(Font::getFont());
    bottom.setCharacterSize(30);
    bottom.setString(s);
}

void Rank::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(top);
    window.draw(bottom);
}

sf::FloatRect Rank::getGlobalBounds() const
{
    return top.getGlobalBounds();
}

void Rank::setPosition(const sf::Vector2f& position)
{
    if(s == "10")
        bottom.setPosition({position.x +105, position.y +165});
    else
        bottom.setPosition({position.x +115, position.y +165});

    top.setPosition(position);
}

void Rank::setColor(const sf::Color color)
{
    top.setColor(color);
    bottom.setColor(color);
}

int Rank::count()
{
    return value;
}

bool Rank::operator==(const Rank &s1)
{
    return (s1.s == s);
}

std::string Rank::toString() const {
    return s;
}

