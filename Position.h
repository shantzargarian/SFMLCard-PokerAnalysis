//
// Created by Shant Zargarian on 2/15/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_POSITION_H
#define CS3A_SPRING23_SFMLCARD_POSITION_H

#include<SFML/Graphics.hpp>

class Position {

public:
    template <typename T, typename S>
    static void center(const T& constObj, S& obj);

    template <typename T, typename S>
    static void topLeft(const T& constObj, S& obj);

    template <typename T, typename S>
    static void bottomRight(const T& constObj, S& obj);
};

#include "Position.cpp"
#endif //CS3A_SPRING23_SFMLCARD_POSITION_H
