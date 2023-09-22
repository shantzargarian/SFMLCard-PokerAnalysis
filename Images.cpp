//
// Created by Dave R. Smith on 2/14/23.
//

#include "Images.h"

std::vector<sf::Texture> Images::images(LAST_SUIT, sf::Texture());

std::string Images::getPath(Suits suit)
{
    switch(suit)
    {
        case HEARTS: return "suits/heart.png";
        case DIAMONDS: return "suits/diamonds.png";
        case SPADES: return "suits/spades.png";
        case CLUBS: return "suits/club.png";
    }
}

void Images::loadFile(Suits suit)
{
    images[suit].loadFromFile(getPath(suit));
}

sf::Texture& Images::getImage(Suits suit)
{
    loadFile(suit);
    return images[suit];
}