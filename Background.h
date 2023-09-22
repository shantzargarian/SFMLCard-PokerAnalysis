//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Background : public sf::Drawable {
private:
    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Background();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getGlobalBounds() const;
    void setPosition(const sf::Vector2f& position);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
};

#endif // BACKGROUND_H

