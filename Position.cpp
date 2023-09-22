//
// Created by Shant Zargarian on 2/15/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_POSITION_CPP
#define CS3A_SPRING23_SFMLCARD_POSITION_CPP
#include "Position.h"

template <typename T, typename S>
void Position::center(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({
        bounds.left + bounds.width/2 - obj.getGlobalBounds().width/2,
        bounds.top + bounds.height/2 - obj.getGlobalBounds().height/2
    });
}

template <typename T, typename S>
void Position::topLeft(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition(bounds.left, bounds.top);
}




#endif