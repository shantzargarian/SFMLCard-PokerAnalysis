//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_CARD_H
#define CS3A_SPRING23_SFMLCARD_CARD_H

#include "Background.h"
#include "Rank.h"
#include "Suit.h"
#include "Ranks.h"
#include "Suits.h"
#include "Position.h"
#include <SFML/Graphics.hpp>

class Card : public sf::Drawable
{
private:
    Rank rnk;
    Suit sut;
    Suits sts;
    Ranks rnks;
    Background b;
    sf::Color c;
    sf::Sprite sprite;
public:
    Card(Ranks r, Suits s);
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::string toString() const;
    Ranks getRank() const;
    Suits getSuit() const;
    sf::Sprite toSprite() const;
    sf::Sprite getCardSprite();
    const Background& getBackground() const;

};



#endif //CS3A_SPRING23_SFMLCARD_CARD_H
