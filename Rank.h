//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_RANK_H
#define CS3A_SPRING23_SFMLCARD_RANK_H

#include <SFML/Graphics.hpp>
#include "Ranks.h"
#include "Font.h"
#include "Position.h"
class Rank : public sf::Drawable
{
private:
    int value;
    sf::Text top, bottom;
    std::string s;

public:
    Rank();
    Rank(Ranks rank);

    int count();

    void setPosition(const sf::Vector2f& position);
    void setColor(sf::Color color);
    sf::FloatRect getGlobalBounds() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const ;
    bool operator == (const Rank& s1);
    std::string toString() const;
};


#endif //CS3A_SPRING23_SFMLCARD_RANK_H
