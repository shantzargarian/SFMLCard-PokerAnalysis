//
// Created by Dave R. Smith on 2/14/23.
//

#include "Suit.h"

Suit::Suit(Suits suit)
{
    suitType = suit;
    sprite.setTexture(Images::getImage(suitType));

    switch (suitType)
    {
        case HEARTS:
            color = sf::Color::Red;
            sprite.setScale(0.3,0.3);
            break;
        case DIAMONDS:
            color = sf::Color::Red;
            sprite.setScale(0.1,0.1);
            break;
        case CLUBS:
            color = sf::Color::Black;
            sprite.setScale(0.3,0.3);
            break;
        case SPADES:
            color = sf::Color::Black;
            sprite.setScale(0.05,0.05);
            break;
        default:
            color = sf::Color::White;
            break;
    }

    setColor(color);
}

sf::FloatRect Suit::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

void Suit::draw(sf::RenderTarget &window, sf::RenderStates event) const
{
    window.draw(sprite);
}

void Suit::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

sf::Color Suit::getColor()
{
    return color;
}

std::string Suit::toString() const {
    switch (suitType) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
        default: return "Invalid suit";
    }
}

