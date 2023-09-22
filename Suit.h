//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_SUIT_H
#define CS3A_SPRING23_SFMLCARD_SUIT_H
#include <SFML/Graphics.hpp>
#include "Suits.h"
#include "Images.h"
class Suit : public sf::Sprite
{
private:
    Suits suitType;
    sf::Color color;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Suit();
    Suit(Suits suit);

    void setPosition(const sf::Vector2f& position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates event) const;
    sf::FloatRect getGlobalBounds() const;
    sf::Color getColor();
    std::string toString() const;

};



#endif //CS3A_SPRING23_SFMLCARD_SUIT_H
