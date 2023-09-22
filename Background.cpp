//
// Created by Dave R. Smith on 2/14/23.
//

#include "Background.h"

Background::Background()
{
    rect.setTexture(&texture);
    rect.setSize(sf::Vector2f(140, 200));
}

void Background::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
}

sf::FloatRect Background::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}

void Background::setPosition(const sf::Vector2f& position)
{
    rect.setPosition(position);
}

unsigned int Background::getWidth() const {
    return sprite.getTextureRect().width * sprite.getScale().x;
}

unsigned int Background::getHeight() const {
    return sprite.getTextureRect().height * sprite.getScale().y;
}

