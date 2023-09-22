//
// Created by Dave R. Smith on 2/14/23.
//
#include <algorithm>
#include <random>
#include "Background.h"
#include "Card.h"
#include "Ranks.h"
#include "Position.h"

Card::Card(Ranks r, Suits s)
        : rnk(r), sut(s)
{
    rnks = r;
    sts = s;

    c = sut.getColor();
    rnk.setColor(c);
}

void Card::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    b.draw(target, states);
    rnk.draw(target, states);
    sut.draw(target, states);
}

void Card::setPosition(const sf::Vector2f &position)
{
    b.setPosition(position);
    rnk.setPosition(position);
    sut.setPosition(position);

    Position::center(b,sut);
}

std::string Card::toString() const {
    return rnk.toString() + " of " + sut.toString();
}

Ranks Card::getRank() const {
    return rnks;
}

Suits Card::getSuit() const {
    return sts;
}

sf::Sprite Card::toSprite() const {
    sf::RenderTexture texture;
    texture.create(100, 150);
    texture.clear(sf::Color::Transparent);
    this->draw(texture, sf::RenderStates::Default);
    texture.draw(rnk);
    texture.draw(sut);

    texture.display();
    sf::Sprite sprite;
    sprite.setTexture(texture.getTexture());
    return sprite;
}

sf::Sprite Card::getCardSprite() {
    sf::RenderTexture texture;
    texture.create(b.getWidth(), b.getHeight());
    texture.clear(sf::Color::Transparent);

    // Draw the card (which includes the background, rank, and suit) to the texture
    texture.draw(*this);
    texture.display();

    sf::Sprite sprite(texture.getTexture());
    return sprite;
}



const Background& Card::getBackground() const {
    return b;
}



